/*
 * 算法：多维前缀和 (常用于多维度的体积限制/容斥)
 * 复杂度：O(维度 * N^维度)
 */
#include <bits/stdc++.h>
using namespace std;

void MultiDimPrefixSum() {
    int n = 100;
    vector<vector<vector<int>>> w(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

    // 正向做 3 次，就是 3 维前缀和
    // 第一维累加
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) w[k][i][j] += w[k - 1][i][j];

    // 第二维累加
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) w[k][i][j] += w[k][i - 1][j];

    // 第三维累加
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) w[k][i][j] += w[k][i][j - 1];
}