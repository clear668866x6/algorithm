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

    vector<vector<i64>> f((1 << n), vector<i64>(n + 1, 1e18));

    for (int i = 0; i < n; i++) {
        f[1 << i][i] = cost[1][s[i] - 'a' + 1] + t;
    }

    for (int state = 1; state < (1 << n); state++) {
        for (int j = 0; j < n; j++) {
            if (!(state >> j & 1) || f[state][j] == 1e18) continue;
            i64 t2 = __builtin_popcount(state & ((1 << j) - 1)) + 1;
            for (int i = 0; i < n; i++) {
                if (state >> i & 1) continue;
                i64 t1 = __builtin_popcount(state & ((1 << i) - 1));
                int nw = state | (1 << i);
                i64 del = abs(t1 - t2);
                f[nw][i] = min(f[nw][i], f[state][j] + cost[s[j] - 'a' + 1][s[i] - 'a' + 1] + t + (i64)del * t);
            }
        }
    }

    i64 mn = 1e18;
    for (int i = 0; i < n; i++) mn = min(mn, f[(1 << n) - 1][i]);
    cout << mn << '\n';
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