#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> s(n + 2, vector<int>(m + 2, 0));

    auto calc = [&](int x1, int y1, int x2, int y2, int val) {
        if (x1 > x2 || y1 > y2) return;
        x1 = max(1, x1);
        y1 = max(1, y1);
        x2 = min(n, x2);
        y2 = min(m, y2);

        if (x1 > x2 || y1 > y2) return;
        s[x1][y1] += val;
        s[x2 + 1][y2 + 1] += val;
        s[x2 + 1][y1] -= val;
        s[x1][y2 + 1] -= val;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d = a[i][j];
            if (!d) {
                calc(i, j, i, j, 1);
            } else {

                calc(i - d, j - d, i - d, j + d, 1);
                calc(i - d + 1, j - d, i + d - 1, j - d, 1);
                calc(i + d, j - d, i + d, j + d, 1);
                calc(i - d + 1, j + d, i + d - 1, j + d, 1);
            }
        }
    }

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

    int ans = -1, x = 0, y = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans < s[i][j]) {
                ans = s[i][j];
                x = i, y = j;
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != max(abs(i - x), abs(j - y))) {
                res++;
            }
        }
    }

    cout << res;
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