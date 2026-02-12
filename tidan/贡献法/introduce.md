### 贡献法 (Contribution Technique)
**核心逻辑**：不要计算 $\sum f(\text{subset})$，而是计算 $\sum (\text{element} \times \text{count of subsets containing element})$。即“算每个元素被用了多少次”。

#### 1. AtCoder Beginner Contest 186 D - Sum of difference
*   **题意**：计算数组中所有两两差值的绝对值之和 $\sum_{i<j} |A_i - A_j|$。
*   **难度**：入门级贡献法。
*   **解法提示**：排序后，考虑每个 $A_i$ 在公式里作为“被减数”出现了几次，作为“减数”出现了几次。推导出一个带 $i$ 和 $N$ 的公式。

#### 2. Codeforces 817 D. Imbalanced Array (Rating 1800-1900)
*   **简介**：**贡献法 + 单调栈** 的教科书级题目。
*   **题意**：给定数组，求所有连续子数组的 $(\max - \min)$ 之和。
*   **思路**：
    *   答案 $= \sum \text{所有子数组的max} - \sum \text{所有子数组的min}$。
    *   问题转化为：对于每个元素 $A_i$，它是多少个子数组的最大值？它是多少个子数组的最小值？
    *   你需要找到 $A_i$ 左边第一个比它大的位置 $L$，和右边第一个比它大的位置 $R$。区间 $(L, R)$ 内所有跨过 $i$ 的子数组都以 $A_i$ 为最大值。
*   **技巧**：利用 **单调栈 (Monotonic Stack)** 在 $O(N)$ 时间内求出每个元素的左右边界。这题对于 1600+ 选手是必修课。

#### 3. Codeforces 1151 E. Number of Components (Rating 1800)
*   **简介**：图论/思维上的贡献法。
*   **题意**：给定一个数组 $A$，对于所有可能的数值区间 $[l, r]$，只保留数组中值在 $[l, r]$ 之间的元素，形成若干个连通块。求所有 $[l, r]$ 对应的连通块数量之和。
*   **思路**：
    *   连通块数量 = 点数 - 边数（对于森林）。
    *   分别计算“点在 $[l, r]$ 出现的次数”和“边在 $[l, r]$ 出现的次数”。
    *   转化为：一个点 $A_i$ 会被多少个 $[l, r]$ 区间包含？一条边 $(A_i, A_{i+1})$ 会被多少个区间包含？
    *   非常巧妙的贡献法思维。

专题一：贡献法 (Contribution Technique) & 计数思维
核心逻辑：不直接算总和，而是算每个元素（数字、边、位）对答案贡献了多少次。常结合单调栈、组合数学、树上DFS。
第一阶段：思维觉醒 (Rating 1400 - 1600)
这里的题目主要考察“每个元素出现了多少次”的简单推导。
AtCoder ABC 186 D - Sum of difference (基础必做，排序+前缀和思想)
CF 1151 E - Number of Components (Rating 1800, 但思维简单，点-边容斥贡献)
CF 1278 B - A and B (数学构造，考虑每一步的贡献)
CF 1365 C - Rotation Matching (桶计数，位置偏移量的贡献)
CF 1399 C - Boats Competition (暴力枚举和，计算Pair贡献)
CF 1196 D2 - RGB Substring (hard version) (滑动窗口+贡献)
CF 1542 B - Plus and Multiply (数论贡献，取模循环)
CF 1551 C - Interesting Story (贪心+贡献，对每个字母单独计算贡献)
ABC 173 C - H and V (暴力枚举行列的贡献)
CF 1512 E - Permutation by Sum (构造，每个位置数值的分配)
第二阶段：单调栈与位运算 (Rating 1600 - 1900)
这是你当前分段最需要攻克的区域，重点是 Sum of Max/Min 模型。
CF 817 D - Imbalanced Array (Rating 1800, 经典单调栈贡献，必做)
CF 1773 E - Easy Assembly (思维，计算需要分裂多少次，即相邻对的贡献)
CF 1324 F - Maximum White Subtree (换根DP，树上每个节点的贡献)
CF 1208 E - Let Them Slide (Rating 1900, 窗口最大值的贡献，需线段树或单调队列)
CF 1420 C1/C2 - Pokémon Army (贪心+DP，波峰波谷的贡献)
CF 1475 G - Strange Beauty (数论DP，因倍数链的贡献)
CF 1360 G - A/B Matrix (构造，每行每列的计数贡献)
CF 1081 C - Colorful Bricks (组合数学，不同颜色的贡献)
CF 1691 D - Max GEQ Sum (Rating 1800, 单调栈+线段树，判断最大值是否贡献过大)
ABC 295 E - Kth Number (期望贡献，非常有价值)
第三阶段：树上与复杂计数 (Rating 1900 - 2200)
结合了图论、概率期望或复杂数据结构。
CF 543 D - Semi-Common Ancestors (树形DP，路径贡献)
CF 1183 H - Subsequences (DP，子序列自动机思想，计算不同字符的贡献)
CF 1527 C - Sequence Pair Weight (Hash表+前缀和，相同元素对答案的贡献)
CF 1227 D - Optimal Subsequences (离线+树状数组，值域上的贡献)
CF 1555 E - Boring Segments (双指针+线段树，区间的覆盖贡献)
CF 1102 F - Elongated Matrix (状压DP，最小差值的贡献)
CF 895 C - Square Subsets (线性基/状压DP，质因子的XOR贡献)
CF 1118 F1/F2 - Tree Cutting (DFS序/树上差分，边对分割颜色的贡献)
ABC 253 F - Operations on a Matrix (差分+树状数组，操作对特定查询的贡献)
CF 915 E - Physical Education Lessons (ODT/线段树，区间覆盖长度贡献)
