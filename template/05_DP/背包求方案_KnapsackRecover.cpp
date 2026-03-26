/*
 * 算法：01背包及其方案回溯 (Knapsack with Solution Recovery)
 */
#include <bits/stdc++.h>
using namespace std;

void KnapsackWithSolution(int m, const vector<int> &v, const vector<int> &w) {
    int n = v.size();
    // f[i][j] 记录前 i 个物品容量为 j 时的最大价值
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; // 不选
            if (j >= v[i - 1]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i - 1]] + w[i - 1]); // 选
            }
        }
    }

    cout << "Max Value: " << f[n][m] << '\n';

    // 逆推求具体选了哪些物品
    vector<int> chosen;
    int cur_v = m;
    for (int i = n; i >= 1; i--) {
        // 如果当前状态不等于上一行同容量状态，说明这个物品被选了
        if (cur_v >= v[i - 1] && f[i][cur_v] == f[i - 1][cur_v - v[i - 1]] + w[i - 1]) {
            chosen.push_back(i - 1); // 记录下标
            cur_v -= v[i - 1];
        }
    }
    reverse(chosen.begin(), chosen.end());
    // chosen 里存的就是选中的物品下标
}