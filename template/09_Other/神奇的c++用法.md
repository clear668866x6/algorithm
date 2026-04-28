


既然你有着如此极致的追求，想要真正的**“大满足”、“全覆盖”、“系统性”**，那我们今天就不再挤牙膏了。

我要把 C++ 标准库（STL）和 GCC 扩展中**所有在算法竞赛（OI/ICPC/Codeforces）中有实战价值的特性**，完完整整、毫无保留地给你铺开！这绝对是你能在中文互联网上看到的**最硬核、最全面的现代 C++ 算法竞赛速查宝典**。

准备好你的收藏夹，我们将把整个 STL 按照**底层语法、算法库、数值计算、数据结构、随机化与扩展库**五个绝对系统的维度进行地毯式轰炸。

---

# 🏆 现代 C++ 算法竞赛系统级全景图 🏆

## 维度一：现代 C++ 语言核心降维打击 (Language Features)
*这些不是函数，而是编译器层面的魔法，能让你的代码缩短 30% 以上。*

| 特性名 | 引入版本 | 解决的痛点 / 竞赛用法 |
| :--- | :--- | :--- |
| **`auto` / `decltype`** | C++11 | 自动类型推导。再也不用写 `vector<pair<int, int>>::iterator` 了。 |
| **Range-based for** | C++11 | `for(int x : a)` 替代老式循环，结合引用 `for(auto& x : a)` 可直接修改原数组。 |
| **泛型 Lambda** | C++14 | `auto dfs = [&](auto& self, int u){}` 完美替代耗时的 `std::function`，写出常数极小的树上局部 DFS。 |
| **结构化绑定** | C++17 | `auto [u, v, w] = edges[i];` 瞬间解包 tuple/pair/结构体，可读性拉满。 |
| **If-Init 语句** | C++17 | `if (auto it = s.find(x); it != s.end())` 把变量作用域严格限制在 if 块内。 |
| **`<=>` 飞船运算符** | C++20 | `auto operator<=>(const Node&) const = default;` 自动按字典序实现所有比较逻辑（`<, >, ==`）。 |
| **Deduced `this`** | C++23 | `auto dfs = [&](this auto&& self, int u){}` 连 `self` 都不用传了，终极优雅的局部递归。 |
| **GCC: `__int128_t`** | GCC | 128位整数！当你做乘法可能会爆 `long long`，但又不想写高精度时，直接强转它！（需手写输入输出） |

---

## 维度二：`<algorithm>` 算法库全家桶（The Brain）
*绝大多数 CF 选手只用过其中不到 20%，但其实每一个都能替代你手写的 10 行代码。*

### 1. 查找与统计 (O(N))
*   `count(A, val)` / `count_if(A, lambda)`：统计等于某值或满足条件的个数。
*   `find(A, val)` / `find_if(A, lambda)`：查找第一个满足条件的元素。
*   `any_of(A, lambda)`：判断是否**存在**元素满足条件（返回 bool）。
*   `all_of(A, lambda)`：判断是否**所有**元素满足条件。
*   `none_of(A, lambda)`：判断是否**没有**元素满足条件。
*   `mismatch(A, B)`：找两个数组或字符串的**第一个不同位置**（求 LCP 最长公共前缀的暴力神器）。

### 2. 数组修改与填充 (O(N))
*   `fill(A, val)`：全部赋值为 `val`（比 `memset` 安全，可以填任何类型和非 0/-1 的数）。
*   `replace(A, old_val, new_val)`：把数组里所有的 $X$ 替换成 $Y$。
*   `reverse(A)`：原地翻转数组。
*   `rotate(A, mid)`：将数组前缀平移到末尾，常用于字符串循环同构处理。
*   `unique(A)`：去除**相邻**重复元素（注意：调用前必须先 `sort`）。
*   `transform(A, B, op)`：将数组 A 中的元素经过操作 `op` 放入数组 B（比如数组全变负数）。

### 3. 排序与排列 (O(N log N) 或 O(N))
*   `sort(A)`：默认升序。
*   `stable_sort(A)`：归并排序！当两个元素相等时，保留它们原有的相对顺序。
*   `nth_element(A, mid)`：**$O(N)$ 求第 K 大 / 求中位数**，比 `sort` 快极其多！
*   `next_permutation(A)`：原地将数组变成**下一个字典序**的排列，如果已经是最后一种返回 `false`（暴力枚举排列的神）。
*   `prev_permutation(A)`：上一个排列。

### 4. 二分查找全家桶 (O(log N))
*(前提：数组已经是有序的)*
*   `lower_bound(A, val)`：找第一个 **$\ge val$** 的迭代器。
*   `upper_bound(A, val)`：找第一个 **$> val$** 的迭代器。
*   `equal_range(A, val)`：同时返回 `[lower_bound, upper_bound)` 两个迭代器，方便查某个数字出现了几次。
*   `binary_search(A, val)`：只返回 `true/false`，判断是否存在。
*   **`partition_point(A, lambda)`**：在布尔数组 `[T, T, ..., F, F]` 中找第一个 `False` 的位置，**二分答案终极利器**。

### 5. 极值与堆操作 (O(N) 或 O(log N))
*   `min_element(A)` / `max_element(A)`：找数组中的最小值/最大值的迭代器。
*   `minmax_element(A)`：同时找最大和最小，只要 $1.5 N$ 次比较。
*   `clamp(x, min_val, max_val)`：把 $x$ 限制在 $[min, max]$ 之间（C++17）。
*   `make_heap(A)`：$O(N)$ 将一个 `vector` 原地建堆。
*   `push_heap(A)` / `pop_heap(A)`：$O(\log N)$ 维护数组堆结构。

### 6. 集合操作 (O(N+M))
*(前提：两个数组都已排好序)*
*   `set_intersection(A, B, out)`：求交集（找两个数组共有的元素）。
*   `set_union(A, B, out)`：求并集。
*   `set_difference(A, B, out)`：求差集（在 A 中但不在 B 中）。

---

## 维度三：`<numeric>` 与 `<bit>` 极速数学库 (The Engine)
*这里的函数常数极小，因为它们大多被编译器直接映射为了 CPU 硬件指令！*

### 1. `<numeric>` 数值计算
*   **`iota(A, start_val)`**：$O(N)$ 用 `start, start+1, start+2...` 填满数组。**间接排序（Argsort）必备**。
*   **`accumulate(A, init_val)`**：$O(N)$ 求和。注意：如果数组是 `long long`，`init_val` 必须写 `0LL`，否则会按 `int` 溢出计算！
*   **`inclusive_scan(A, B)`**：(C++17) $O(N)$ 极速生成**前缀和**数组。
*   **`adjacent_difference(A, B)`**：$O(N)$ 生成**差分**数组。
*   **`gcd(x, y)` / `lcm(x, y)`**：(C++17) 最大公约数和最小公倍数，取代手写欧几里得，自动推导类型。
*   **`midpoint(a, b)`**：(C++20) 绝对不会爆内存（溢出）的求中点函数。

### 2. `<bit>` 位运算黑魔法 (C++20)
*(所有操作都是 O(1)，直接操作寄存器！)*
*   `popcount(x)`：查二进制里有几个 1。
*   `countl_zero(x)`：前导 0 的个数。
*   `countr_zero(x)`：后缀 0 的个数（找 `lowbit` 的位数极其有用！）。
*   `has_single_bit(x)`：是不是 2 的幂。
*   `bit_width(x)`：表示这个数最少需要几个二进制位（其实就是 $\lfloor \log_2 x \rfloor + 1$）。
*   `bit_ceil(x)` / `bit_floor(x)`：找距离 $x$ 最近的 2 的幂（建线段树时用来算数组大小非常爽）。

---

## 维度四：数据结构容器的进阶用法 (The Arsenal)
*这部分涵盖如何把标准容器玩出花来。*

### 1. `std::vector` 的内存控制
*   `v.shrink_to_fit()`：当你删除了很多元素，`vector` 占用的内存并不会减少，用这个可以释放多余内存。
*   `v.reserve(N)`：在 `push_back` 之前预先分配空间，**避免动态扩容带来的巨大 $O(N)$ 拷贝常数**，防止 TLE！

### 2. `std::string_view` (C++17)
*   替代 `std::string`。在做字符串哈希或 KMP 时，`s.substr()` 会产生 $O(N)$ 的拷贝，而 `string_view` 永远是 $O(1)$，因为它只是原字符串的“观察者”（指针+长度）。

### 3. `std::array` (C++11)
*   替代原生的 `int dp[100][100]`。原生数组不能直接赋值，不能当参数按值传递。`std::array<std::array<int, 100>, 100> dp;` 存在栈上，速度极快，支持 `auto dp2 = dp;` 直接深拷贝！

### 4. `std::priority_queue` 的优雅定义
*   手写比较函数太麻烦？用 Lambda 定义优先队列：
    ```cpp
    auto cmp =[](Node a, Node b) { return a.w > b.w; };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    ```

---

## 维度五：真正的黑魔法 (随机化与 PBDS)
*这是 2000+ 高分段选手对抗出题人（防 Hack）的绝对核心。*

### 1. 高精度真随机数 `<random>` (C++11)
永远**不要**再用 `rand()`！它的上限只有 32767，且在很多系统上是伪随机，极容易被出题人卡掉（比如 Treap 被卡成链）。
```cpp
#include <random>
#include <chrono>

// mt19937_64 是 64 位的高质量梅森旋转算法随机数生成器
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void test() {
    long long random_num = rng(); // 随便生成一个超大的高质量随机数
    
    // 生成 [L, R] 范围内的均匀分布随机数
    std::uniform_int_distribution<long long> dist(1, 1000000);
    long long x = dist(rng); 
    
    // O(N) 原地随机打乱数组（替代以前的 random_shuffle）
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::shuffle(a.begin(), a.end(), rng);
}
```

### 2. PBDS - Policy-Based Data Structures
这是 GCC 编译器专属扩展（CF 和各大平台均支持）。只需引入头文件，瞬间获得神级数据结构。
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
```

#### A. 超强哈希表 (`gp_hash_table`)
`std::unordered_map` 被 Hack 是因为用的拉链法处理冲突。PBDS 用的是探测法，常数只有一半。
```cpp
gp_hash_table<int, int> mp; // 用法完全等同于 unordered_map，但极快！
```

#### B. 黑盒平衡树 (Ordered Set)
自带查询排名、查第 K 小的红黑树！
```cpp
template<class T> 
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// os.insert(x), os.erase(x)
// os.order_of_key(x): 严格小于 x 的元素有几个
// *os.find_by_order(k): 第 k 小的元素是谁 (k 从 0 开始)
```

#### C. 可并堆 (Pairing Heap)
做最短路算法或图论启发式合并时，合并两个 `std::priority_queue` 是 $O(N \log N)$ 的。PBDS 的配对堆合并是 **$O(1)$** 的！
```cpp
// 引入对应的 policy
using pq_t = __gnu_pbds::priority_queue<int, std::greater<int>, pairing_heap_tag>;
pq_t pq1, pq2;
pq1.push(1); pq2.push(2);
pq1.join(pq2); // O(1) 合并，pq2 会变为空，元素全部进入 pq1
```

---

## 🧭 系统学习与训练终极指南 🧭

如果上面的内容让你觉得“眼花缭乱”，不知道从何下手。不要慌，这里是为你定制的**体系化修炼路线图**：

### 阶段 1：本地搭建 "CP-Wiki"（你的专属电子词典）
不要去背诵上面的东西。你需要做的是：
在本地电脑上建立一个文件夹，叫 `CP_Modern_Cpp`。
里面建几个文件：
*   `1_Algorithm.cpp` (专门测试和记录 `<algorithm>` 的函数)
*   `2_Numeric_and_Bit.cpp` (专门测试数学运算)
*   `3_PBDS.cpp` (测试哈希表和平衡树)
*   `4_Ranges_and_Views.cpp`

**每天抽 30 分钟**，去 [cppreference.com (中文版)](https://zh.cppreference.com/) 搜索我上面提到的 2~3 个函数，把官方给的示例代码复制到你的 `CP_Modern_Cpp` 文件夹里跑一遍。这就叫“系统化”。

### 阶段 2：强制重构你的代码
从今天起，打开你最近在 CF 上做过的 5 道过了的题。**强迫自己用新特性重写它们！**
*   本来写了 `while(l<=r)` 的，重写用 `std::partition_point`。
*   本来写了 `struct` 且重载了 `<` 的，全部换成 `auto operator<=>(const ...) const = default;`。
*   本来用来找差值的，换成 `std::adjacent_difference`。

### 阶段 3：阅读神级项目的源码
如果你觉得国内博客太碎，我强烈推荐你去看 GitHub 上的顶级 OIer 整理的模板库！
*   去 GitHub 搜索：**`KACTL`** (KTH Algorithm Competition Template Library)。
    *   这是全球公认最精简、最现代、无任何废话的 ICPC 顶级竞赛模板！
    *   你重点看里面 `data-structures` 和 `various` 文件夹里的 C++ 代码，看看世界冠军是怎么压榨 C++ 性能的。
*   去 GitHub 搜索：**`cp-algorithms`** (它是著名的俄罗斯算法网站 e-maxx 的英文开源版)。
    *   这里面的代码风格是极其标准的高手风范。

### 阶段 4：固定你的终极模板
把你需要用到的宏、哈希防 Hack 函数、常量定义，全部封装到一个 `template.cpp` 中。每次打比赛直接从这个文件开始写。

***

**最后的话：**
STL 是一片汪洋大海，你感觉“没学够”是很正常的。但**算法竞赛的重点始终是思维，语言只是剑**。
我今天给你的这把剑（上面的五大维度），已经是最顶尖的“倚天剑”了。把这份清单保存下来，当成你的**技能树（Skill Tree）**，做题时一旦发现“这段逻辑我手写了好多行”，就翻开来看看有没有对应的 STL。

你现在的态度非常棒，保持这个状态，逐点击破，一个月后你会发现你的代码水平（Code Quality）已经超越了 80% 的 CF 选手！祝你早日红名！
