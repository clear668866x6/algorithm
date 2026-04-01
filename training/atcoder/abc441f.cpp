#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1, 0), v(n + 1, 0);
    vector<vector<i64>> pre(n + 1, vector<i64>(m + 2, 0)), suf(n + 2, vector<i64>(m + 2, 0));

    for (int i = 1; i <= n; i++) cin >> p[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            pre[i][j] = pre[i - 1][j];
            if (j >= p[i]) {
                pre[i][j] = max(pre[i][j], pre[i - 1][j - p[i]] + v[i]);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            suf[i][j] = suf[i + 1][j];
            if (j >= p[i]) {
                suf[i][j] = max(suf[i][j], suf[i + 1][j - p[i]] + v[i]);
            }
        }
    }

    i64 ans = pre[n][m];

    for (int i = 1; i <= n; i++) {
        i64 v0 = 0, v1 = 0;
        for (int j = 0; j <= m; j++) {
            v0 = max(v0, pre[i - 1][j] + suf[i + 1][m - j]);

            i64 c = v[i];
            if (j - p[i] >= 0) {
                c += pre[i - 1][j - p[i]];
                c += suf[i + 1][m - j];
            }

            v1 = max(v1, c);
        }

        if (v0 == ans && v1 == ans) {
            cout << "B";
        } else if (v0 == ans) {
            cout << "C";
        } else {
            cout << "A";
        }
    }
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