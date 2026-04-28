### 维度一：容器防 Hack 与“黑魔法”数据结构

在 CF 上，用 `std::unordered_map` 经常会被出题人或老阴逼选手**构造数据 Hack 到 $O(N^2)$** 导致 TLE。下面是高分段选手的标配：

#### 1. 吊打 `unordered_map` 的超级哈希表：`gp_hash_table`
这是 PBDS（GCC 扩展）里的探测法哈希表，常数极小，比 `std::unordered_map` **快 3~6 倍**！
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;

// 用法和 unordered_map 完全一样
gp_hash_table<int, int> mp; 
mp[1] = 2;
```

#### 2. 终极防 Hack 自定义哈希函数 (Custom Hash)
为了防止 `gp_hash_table` 或 `unordered_map` 被特殊数据卡冲突，我们需要引入基于时间戳的随机种子哈希：
```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // chrono::steady_clock 获取高精度时间作为随机数种子
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// 完美防 Hack 的超快哈希表
gp_hash_table<long long, int, custom_hash> safe_mp;
std::unordered_map<long long, int, custom_hash> safe_ump; // 如果不想用 pbds
```

#### 3. `std::multiset` 的致命误区
**痛点**：很多选手在写滑动窗口或平衡树替代品时，想要删除 `multiset` 中的**一个** `x`。
```cpp
std::multiset<int> s = {1, 2, 2, 2, 3};
s.erase(2); // 致命错误！这会把所有的 2 全删光，复杂度 O(k + log N)
s.erase(s.find(2)); // 正确做法！只删除找到的第一个 2，复杂度 O(log N)
```

---

### 维度二：现代 C++ 语法降维打击 (CP 提速核心)

#### 1. 结构体比较的终结者：飞船运算符 `<=>` (C++20)
以前写一个多关键字排序的结构体，要重载 `<`，有时候还要重载 `==`。现在只需**一行代码**，编译器自动按从上到下的顺序帮你生成所有比较逻辑！
```cpp
struct Node {
    int w, v, id;
    // 自动按照 w 为第一关键字，v 为第二，id 为第三比较
    auto operator<=>(const Node&) const = default; 
};

std::vector<Node> a = {{2, 3, 1}, {2, 1, 2}, {1, 5, 3}};
std::ranges::sort(a); 
```

#### 2. 彻底告别 `std::function`：完美递归 Lambda (C++14/C++23)
写 DFS（特别是树上 DFS）时，写在 `main` 函数外的全局变量很污染代码。用 `std::function` 写局部 DFS **常数极大**（因为有动态内存分配和虚函数调用的开销）。
**正确的高效写法（C++14 泛型 Lambda）：**
```cpp
// 传 auto& self 把自己传进去
auto dfs = [&](auto& self, int u, int p) -> void {
    for (int v : adj[u]) {
        if (v != p) self(self, v, u);
    }
};
dfs(dfs, 1, 0);
```
**更超前的写法（C++23 Deduced `this`，目前最新的 CF 编译器已支持！）：**
```cpp
// 极其优雅的自引用
auto dfs = [&](this auto&& self, int u, int p) -> void {
    for (int v : adj[u]) {
        if (v != p) self(v, u);
    }
};
dfs(1, 0); // 直接调用，无需传自己
```

#### 3. 最强视图：`views::enumerate` 与 `views::zip` (C++23)
Python 选手最爱的东西，C++ 终于有了，代码可读性直接起飞！
```cpp
#include <ranges>
std::vector<int> a = {10, 20, 30};

// enumerate: 同时获取下标和值
for (auto [i, val] : std::views::enumerate(a)) {
    std::cout << "Index: " << i << " Value: " << val << "\n";
}

// zip: 同时遍历多个数组（做到完全同步）
std::vector<std::string> b = {"A", "B", "C"};
for (auto[x, y] : std::views::zip(a, b)) {
    std::cout << x << " -> " << y << "\n"; // 输出 10 -> A 等
}
```

---

### 维度三：STL 隐藏的算法神迹 `<algorithm>` 与 `技巧`

#### 1. 字典序神函数：`std::lexicographical_compare`
**场景**：你需要比较两个数组或两个字符串的一段子区间哪个字典序更小（后缀数组、字符串哈希常用）。
```cpp
std::vector<int> a = {1, 2, 3, 4};
std::vector<int> b = {1, 2, 4, 3};
// O(N) 比较两者字典序
bool a_is_smaller = std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
```

#### 2. 最长有序前缀：`std::is_sorted_until`
**场景**：找出一个数组从头开始，最长连续递增的子段。
```cpp
std::vector<int> a = {1, 2, 5, 4, 3};
auto it = std::is_sorted_until(a.begin(), a.end()); 
// it 指向 4，因为 1, 2, 5 是排好序的
int len = std::distance(a.begin(), it); // len = 3
```

#### 3. 找分歧点：`std::mismatch`
**场景**：两个数组/字符串，你想找到它们**从哪个位置开始变得不一样**（LCP 最长公共前缀的最快暴力求法）。
```cpp
std::string s1 = "codeforces";
std::string s2 = "codefights";
auto [it1, it2] = std::mismatch(s1.begin(), s1.end(), s2.begin());
// it1 指向 'r', it2 指向 'i'
```

#### 4. 元组极速打包法：`std::tuple` 的妙用
不想写结构体？直接用 `tuple` 打包变量！`tuple` 自带完美的字典序比较逻辑。
```cpp
#include <tuple>
std::vector<std::tuple<int, int, std::string>> v;
v.emplace_back(1, 2, "abc");
v.emplace_back(1, 1, "def");

std::ranges::sort(v); // 自动按第一、第二、第三个元素排序
```

---

### 维度四：内存与底层常数极限优化

#### 1. 快过 `cin` 和 `scanf` 的解析：`std::from_chars` (C++17)
**场景**：有时题目给了巨大的字符串，要求你将其分割并解析成无数个 `int`。`stoi` 或者 `stringstream` 会产生巨大的内存开销。
`from_chars` 是 C++ 底层用于字符串转数字的 API，**绝对零拷贝、无需动态内存**。
```cpp
#include <charconv>
const char* str = "12345 67890";
int val1, val2;
auto res = std::from_chars(str, str + 5, val1);
// val1 直接变成 12345，res.ptr 指向下一个字符位置
```
*   **速度**：比 `atoi` 快好几倍，是标准库中最快的数字解析器。

#### 2. 避免数组退化与越界神器：`std::span` (C++20)
**场景**：你需要写一个函数，处理 `vector` 的某个片段（比如分治算法）。以前传迭代器非常麻烦，传 `vector` 会发生拷贝。`span` 让你**无开销**地传递连续内存的视图。
```cpp
#include <span>
// span 代替了传 (vector<int>& a, int L, int R)
void solve(std::span<int> sub_arr) {
    // 就像操作普通 vector 一样操作 sub_arr，不产生任何拷贝！
    sub_arr[0] = 99; 
}

std::vector<int> a = {1, 2, 3, 4, 5};
solve(std::span{a}.subspan(1, 3)); // 只把 {2, 3, 4} 传进去
```

#### 3. 栈上内存分配：`std::array` 替代原生数组
**场景**：你平时喜欢写 `int dp[105][105]`。原生数组在做初始化、赋值时很不方便。`std::array` 存储在栈上（与原生数组一样快），但拥有 STL 的全部接口！
```cpp
#include <array>
std::array<std::array<int, 105>, 105> dp;

// 优势 1：一键初始化全 0（或者全其它值），替代 memset
for (auto& row : dp) row.fill(-1);

// 优势 2：支持直接拷贝赋值（原生数组做不到！）
auto dp2 = dp; 
```

#### 4. 高阶位运算补遗：循环移位器 (C++20)
在上一篇讲了 `<bit>` 之后，再补充两个：
*   `std::rotl(x, s)`：将整数 $x$ 的二进制循环左移 $s$ 位（超出高位的 1 会回到低位）。
*   `std::rotr(x, s)`：循环右移 $s$ 位。
*   **用途**：自定义 Hash 混合策略、部分状态压缩或密码学模拟题极速解法。

---

### 最后总结：如何建立自己的“现代模板”？

高分段选手（2000+）通常都会维护一份优雅的 Template。结合我今天讲的，你可以这样组织你的代码：

1.  **宏与类型别名：**
    ```cpp
    using ll = long long;
    using pii = std::pair<int, int>;
    #define all(x) (x).begin(), (x).end() // 如果你偶尔不用 ranges
    ```
2.  **默认引入高级库：**
    ```cpp
    #include <ranges>
    #include <numeric>
    #include <bit>
    #include <span>
    #include <ext/pb_ds/assoc_container.hpp>
    // 以及前面提到的自定义 hash
    ```
3.  **在本地开启编译器高等级警告与 C++20/23 标准：**
    在你的本地 IDE 配置里加上 `-std=c++20 -O2 -Wall -Wextra`，强制自己习惯更现代、更安全的写法。

**STL 的真谛不仅在于“有现成的函数可以调用”，更在于它背后严谨的数学逻辑（比如左闭右开区间）和极端的性能压榨。** 把这些全部融会贯通，你在 1670 分段绝对是“降维打击”级别的代码能力，冲 1900 紫名指日可待！还有什么具体的算法模块（图论、字符串、DP）想了解现代写法的，随时问我！