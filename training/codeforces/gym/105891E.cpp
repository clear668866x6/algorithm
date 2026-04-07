#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    string s;
    cin >> s;

    vector cost(m + 1, vector(m + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cost[i][j];
        }
    }

    vector f((1 << n), vector(n + 1, 1e9));

    f[0][0] = 0;
    for (int state = 0; state < (1 << n); state++) {
        for (int i = 0; i < n; i++) {
            int t1 = __builtin_popcount(state & ((1 << i) - 1)) + 1;
            for (int j = 0; j < n; j++) {
                int t2 = __builtin_popcount(state & ((1 << j) - 1)) + 1;
                int del = abs(t1 - t2);
                f[state | (1 << i)][i] =
                    min(f[state | (1 << i)][i], f[state][j] + cost[s[i] - 'a' + 1][s[j] - 'a' + 1] + t + del * t);
            }
        }
    }

    cout << *min_element(f[(1 << n) - 1].begin(), f[(1 << n) - 1].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}