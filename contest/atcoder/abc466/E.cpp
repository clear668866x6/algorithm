#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    vector<vector<vector<i64>>> f(n + 1, vector<vector<i64>>(2, vector<i64>(k + 2, 0)));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t <= k; t++) {
                if (j - 2 * t >= 0) {
                    f[i][0][j] = max(f[i][0][j], f[i - 1][0][j - 2 * t] + a[i]);
                    if (j >= 1) {
                        f[i][1][j] = max(f[i][1][j], f[i - 1][1][j - 2 * t] + b[i]);
                        if (j - 2 * t - 1 >= 0) {
                            f[i][1][j] = max(f[i][1][j], f[i - 1][0][j - 2 * t - 1] + b[i]);
                        }
                        f[i][0][j] = max(f[i][0][j], f[i - 1][1][j - 2 * t] + a[i]);
                    }
                }
            }
        }
    }

    i64 ans = 0;

    for (int i = 0; i <= k; i++) ans = max({ans, f[n][0][i], f[n][1][i]});

    cout << ans;
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