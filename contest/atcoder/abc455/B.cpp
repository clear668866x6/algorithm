#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n + 1, vector<char>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    int ans = 0;

    for (int h2 = 1; h2 <= n; h2++) {
        for (int h1 = 1; h1 <= h2; h1++) {
            for (int w2 = 1; w2 <= m; w2++) {
                for (int w1 = 1; w1 <= w2; w1++) {
                    bool f = false;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            if (s[i][j] != s[h1 + h2 - i][w1 + w2 - j]) {
                                f = 1;
                                break;
                            }
                        }
                        if (f) break;
                    }
                    if (!f) ans++;
                }
            }
        }
    }

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