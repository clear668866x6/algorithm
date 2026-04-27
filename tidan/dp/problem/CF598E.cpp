#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, K;
    cin >> n >> m >> K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    vector f(30 + 10, vector(30 + 10, vector(50 + 10, 1e9)));

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
            f[i][j][0] = 0;
            if (i * j <= 50) f[i][j][i * j] = 0;
        }
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
            for (int k = 0; k <= 50; k++) {
                for (int t = 1; t <= i - 1; t++) {
                    for (int u = 0; u <= min(k, t * j); u++) {
                        f[i][j][k] = min(f[i][j][k], f[i - t][j][k - u] + f[t][j][u] + j * j);
                    }
                }
                for (int t = 1; t <= j - 1; t++) {
                    for (int u = 0; u <= min(k, t * i); u++) {
                        f[i][j][k] = min(f[i][j][k], f[i][j - t][k - u] + f[i][t][u] + i * i);
                    }
                }
            }
        }
    }

    auto solve = [&]() {
        int n, m, k;
        cin >> n >> m >> k;

        cout << f[n][m][k] << '\n';
    };

    while (t--) {
        solve();
    }

    return 0;
}