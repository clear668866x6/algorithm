#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<i64>> f(n + 1, vector<i64>(4, 0));
    vector<vector<char>> s(3, vector<char>(n + 1, 0));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }

    if (s[1][1] == '?' && s[2][1] == '?') {
        for (int i = 0; i < 4; i++) {
            f[1][i] = 1;
        }
    } else if (s[1][1] == '?' && s[2][1] == '0') {
        f[1][0] = f[1][3] = 1;
    } else if (s[1][1] == '0' && s[2][1] == '?') {
        for (int i = 0; i < 2; i++) {
            f[1][i] = 1;
        }
    } else if (s[1][1] == '?' && s[2][1] == '1') {
        f[1][1] = f[1][2] = 1;
    } else if (s[1][1] == '1' && s[2][1] == '?') {
        f[1][2] = f[1][3] = 1;
    } else if (s[1][1] == '0' && s[2][1] == '0') {
        f[1][0] = 1;
    } else if (s[1][1] == '0' && s[2][1] == '1') {
        f[1][1] = 1;
    } else if (s[1][1] == '1' && s[2][1] == '1') {
        f[1][2] = 1;
    } else {
        f[1][3] = 1;
    }

    vector<vector<int>> p{{1, 2, 3}, {0, 1, 2, 3}, {0, 1, 3}, {0, 1, 2, 3}};

    for (int i = 2; i <= n; i++) {
        if (s[1][i] == '?' && s[2][i] == '?') {
            for (int j = 0; j < 4; j++) {
                for (auto k : p[j]) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        } else if (s[1][i] == '?' && s[2][i] == '0') {
            for (auto k : p[0]) {
                f[i][0] = (f[i][0] + f[i - 1][k]) % mod;
            }
            for (auto k : p[3]) {
                f[i][3] = (f[i][3] + f[i - 1][k]) % mod;
            }
        } else if (s[1][i] == '0' && s[2][i] == '?') {
            for (int j = 0; j < 2; j++) {
                for (auto k : p[j]) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        } else if (s[1][i] == '?' && s[2][i] == '1') {
            for (int j = 1; j < 3; j++) {
                for (auto k : p[j]) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        } else if (s[1][i] == '1' && s[2][i] == '?') {
            for (int j = 2; j < 4; j++) {
                for (auto k : p[j]) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        } else if (s[1][i] == '0' && s[2][i] == '0') {
            for (auto k : p[0]) {
                f[i][0] = (f[i][0] + f[i - 1][k]) % mod;
            }
        } else if (s[1][i] == '0' && s[2][i] == '1') {
            for (auto k : p[1]) {
                f[i][1] = (f[i][1] + f[i - 1][k]) % mod;
            }
        } else if (s[1][i] == '1' && s[2][i] == '1') {
            for (auto k : p[2]) {
                f[i][2] = (f[i][2] + f[i - 1][k]) % mod;
            }
        } else if (s[1][i] == '1' && s[2][i] == '0') {
            for (auto k : p[3]) {
                f[i][3] = (f[i][3] + f[i - 1][k]) % mod;
            }
        }
    }

    i64 ans = 0;
    for (int i = 0; i < 4; i++) ans = (ans + f[n][i]) % mod;

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