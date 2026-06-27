#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    struct E {
        int x, y;
        char c;
    };

    vector<E> a(q + 1);
    for (int i = 1; i <= q; i++) cin >> a[i].x >> a[i].y >> a[i].c;

    vector<vector<char>> ans(n + 1, vector<char>(m + 1, 'A'));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

    for (int i = q; i >= 1; i--) {
        bool f = false;
        for (int x = a[i].x; x >= 1; x--) {
            for (int y = a[i].y; y >= 1; y--) {
                if (vis[x][y]) {
                    if (y == a[i].y) f = 1;
                    break;
                }
                ans[x][y] = a[i].c;
                vis[x][y] = 1;
            }
            if (f) break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
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