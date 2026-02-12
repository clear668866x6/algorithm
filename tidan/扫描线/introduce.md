### 贪心 + 优先队列 + 扫描线
**核心逻辑**：将静态的区间问题转化为动态的“事件流”，在每个时刻维护“当前可用集合”，并做出“最紧迫”或“收益最大”的决策。

这种题目就是转化成截止日期的题目，就是对于这种有取值范围在一定范围的题目都是这么想（扫描线）。

#### 1. Codeforces 555 B. Case of Fugitive (Rating 1800)
*   **简介**：这道题简直是你刚才做的题的“亲兄弟”，甚至是进阶版。
*   **题意**：有 $N$ 个岛屿，$N-1$ 个桥。你需要把桥架在相邻岛屿之间。桥的长度必须满足一定范围。问能否架好。
*   **相似点**：你需要把“桥的长度”看作“车位”，把“岛屿间距的范围”看作“车的 $L, R$”。
*   **解法提示**：把区间按 $L$ 排序，用扫描线扫过桥的长度，把符合条件的区间 $R$ 扔进 PQ，选 $R$ 最小的（EDF策略）。**一定要做这道！**

#### 2. AtCoder Beginner Contest 137 D - Summer Vacation
*   **题意**：你有 $N$ 个工作，每个工作需要 $A_i$ 天完成，给 $B_i$ 报酬。现在离暑假结束还有 $M$ 天。每天只能选一个工作开始做（或者不做）。求最大报酬。
*   **思维转换**：这里是倒着思考（或者正着思考 $M$ 到 $1$）。
*   **解法提示**：在剩下 $k$ 天时，所有 $A_i \le k$ 的工作都可以选。用 PQ 维护当前能做的工作中 $B_i$ 最大的。这是“收益最大优先”，而刚才那题是“截止最早优先”。

#### 3. Codeforces 1526 C2. Potions (Hard Version) (Rating 1600-1700)
*   **简介**：经典的**反悔贪心（Regret Greedy）**。
*   **题意**：你从左走到右喝药水，有些药水加血，有些扣血。血量不能小于 0。问最多能喝多少瓶。
*   **为什么推荐**：虽然不是区间匹配，但它同样是“遍历 + 优先队列”。
*   **解法提示**：遇到扣血的药水，如果能喝就喝，把扣血量扔进 PQ。如果喝了会死，看看 PQ 里有没有比当前这瓶“毒性更大”的已喝药水？如果有，把那瓶吐出来，换喝当前这瓶（因为它毒性更小，对未来更好）。

核心逻辑：将静态区间转化为动态事件点，利用优先队列（PQ）、Set 或线段树维护“当前有效集合”。
第一阶段：区间基础与差分 (Rating 1400 - 1600)
熟悉“左端点+1，右端点-1”以及简单的排序贪心。
CF 1000 C - Covered Points Count (坐标离散化+差分扫描)
CF 1133 C - Balanced Team (排序+双指针/滑动窗口)
CF 1249 C2 - Good Numbers (贪心+位运算思维)
CF 1341 C - Nastya and Strange Generator (模拟，扫描线检查)
CF 1369 C - RationalLee (排序贪心，分配策略)
CF 1409 C - Yet Another Array Restoration (构造+扫描)
CF 1461 C - Random Events (概率扫描，从后往前看)
CF 997 C - Sky Arithmetics (组合数学，但涉及行列扫描思想)
ABC 183 D - Water Heater (典型的差分扫描线)
CSES 1619 - Restaurant Customers (最纯粹的扫描线入门)
第二阶段：带悔贪心与优先队列 (Rating 1600 - 1900)
这是你刚做的 CF 555B 所在的区域，也是比赛中得分的关键。
CF 555 B - Case of Fugitive (你刚做的原题，务必复习)
CF 1526 C2 - Potions (Hard Version) (反悔贪心经典，必做)
CF 845 C - Two TVs (简单的两路扫描)
CF 732 D - Exams (二分答案+贪心扫描，判定是否能考完)
CF 1157 C2 - Increasing Subsequence (hard) (双指针贪心)
CF 1707 B - Difference Array (差分数组的模拟)
CF 1353 D - Constructing the Array (优先队列维护区间长度)
ABC 214 E - Packing Under Range Regulations (强推，和停车位题极像，PQ+扫描线)
CF 1140 C - Playlist (维护Top K的和，PQ+扫描)
CF 803 C - Maximal GCD (数论构造，但有点贪心分配的感觉)
第三阶段：高阶扫描与数据结构结合 (Rating 1900 - 2200)
涉及二维扫描线、线段树优化贪心。
CF 1187 E - Tree Painting (换根DP，也可以看作树上扫描)
CF 1296 E1/E2 - String Coloring (Dilworth定理/最长下降子序列，用扫描线+Set维护)
CF 1328 E - Tree Queries (DFS序+LCA，树上区间问题)
CF 1379 C - Choosing Flowers (枚举+二分/后缀和，一种特殊的扫描)
CF 1108 E2 - Array and Segments (枚举极值点+线段树扫描)
CF 814 C - An impassioned circulation of affection (滑动窗口+枚举)
CF 1198 B - Welfare State (时间轴上的扫描/线段树)
CF 1555 E - Boring Segments (双指针+线段树区间覆盖)
ABC 127 F - Absolute Minima (两个对顶堆维护中位数扫描)
CF 960 C - Subsequence Counting (构造，基于位贡献)
CF 853 B - Jury Meeting (正反两遍扫描线预处理)
