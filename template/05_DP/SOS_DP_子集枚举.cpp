/*
 * 算法：SOS DP (Sum Over Subsets) / 高效枚举子集
 * 复杂度：枚举子集的子集总复杂度为 O(3^N)
 */
#include <bits/stdc++.h>
using namespace std;

void SubsetDP() {
    int n = 10;
    vector<int> f(1 << n, 0);

    // 1. 高阶技巧：枚举所有状态 i，然后再枚举 i 的所有子集 j
    for (int i = 0; i < (1 << n); i++) {
        for (int j = i; j > 0; j = (j - 1) & i) {
            // j 是 i 的子集
            // i ^ j 是 i 的另一个补集
            f[i] = max(f[i], f[j] + f[i ^ j]);
        }
    }

    // 2. SOS DP (FMT 快速莫比乌斯变换)：求所有子集的和 (时间 O(N * 2^N))
    // f[mask] = sum(a[sub]) where sub is subset of mask
    vector<int> a(1 << n, 1);
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << i)) {
                a[mask] += a[mask ^ (1 << i)];
            }
        }
    }
}