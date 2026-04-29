#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> s(3, vector<char>(n + 1, 0));
    vector w(3, vector(n + 1, 0));

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'A') w[i][j] = 1;
        }
    }

    vector<int> f(n + 2, -1), g(n + 2, -1), h(n + 2, -1);

    f[0] = 0;

    for (int i = 2; i <= n; i++) {
        if (h[i - 1] != -1) {
            int t = (w[1][i - 1] + w[1][i] + w[2][i]) >= 2;
            f[i] = max(f[i], h[i - 1] + t);
        }
        if (g[i - 1] != -1) {
            int t = (w[2][i - 1] + w[1][i] + w[2][i]) >= 2;
            f[i] = max(f[i], g[i - 1] + t);
        }

        if (i - 2 >= 0 && f[i - 2] != -1) {
            int t1 = (w[1][i - 1] + w[2][i - 1] + w[2][i]) >= 2;
            int t2 = (w[1][i - 1] + w[1][i] + w[2][i - 1]) >= 2;
            h[i] = max(h[i], f[i - 2] + t1);
            g[i] = max(g[i], f[i - 2] + t2);
        }

        if (i - 3 >= 0) {
            if (f[i - 3] != -1) {
                int t1 = (w[1][i - 2] + w[1][i - 1] + w[1][i]) >= 2;
                int t2 = (w[2][i - 2] + w[2][i - 1] + w[2][i]) >= 2;
                int t3 = (w[1][i - 2] + w[2][i - 2] + w[2][i - 1]) >= 2;
                int t4 = (w[1][i - 1] + w[1][i] + w[2][i]) >= 2;
                int t5 = (w[1][i - 2] + w[1][i - 1] + w[2][i - 2]) >= 2;
                int t6 = (w[1][i] + w[2][i - 1] + w[2][i]) >= 2;
                f[i] = max({f[i], f[i - 3] + t1 + t2, f[i - 3] + t3 + t4, f[i - 3] + t5 + t6});
            }
            if (g[i - 3] != -1) {
                int t1 = (w[1][i - 2] + w[1][i - 1] + w[1][i]) >= 2;
                int t2 = (w[2][i - 3] + w[2][i - 2] + w[2][i - 1]) >= 2;
                g[i] = max(g[i], g[i - 3] + t1 + t2);
            }

            if (h[i - 3] != -1) {
                int t1 = (w[1][i - 3] + w[1][i - 2] + w[1][i - 1]) >= 2;
                int t2 = (w[2][i - 2] + w[2][i - 1] + w[2][i]) >= 2;
                h[i] = max(h[i], h[i - 3] + t1 + t2);
            }
        }
    }

    cout << f[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}