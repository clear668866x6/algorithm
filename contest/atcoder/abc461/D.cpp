#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    auto s = a;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i - 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] += s[i][j - 1];
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    };

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int p = i; p <= n; p++) {
                auto cal = [&](int x) {
                    int l = j - 1, r = m + 1;
                    while (l + 1 < r) {
                        int mid = (l + r) / 2;
                        if (get(i, j, p, mid) >= x)
                            r = mid;
                        else
                            l = mid;
                    }
                    return r;
                };

                int del = cal(k + 1) - cal(k);
                ans += del;
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