#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n + 1, vector<char>(m + 1, 0));
    int stx = 0, sty = 0, edx = 0, edy = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') stx = i, sty = j;
            if (s[i][j] == 'G') edx = i, edy = j;
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    queue<array<int, 3>> q;
    vector lst(n + 1, vector(m + 1, vector<array<int, 3>>(4, {0, 0, 0})));
    vector vis(n + 1, vector(m + 1, vector<int>(4, 0)));
    for (int i = 0; i < 4; i++) q.push({stx, sty, i}), vis[stx][sty][i] = 1;
    bool f = false;
    while (!q.empty()) {
        auto [x, y, dir] = q.front();
        q.pop();

        if (s[x][y] == 'G') {
            f = 1;

            cout << "Yes\n";

            int x = edx, y = edy;
            string ans;
            while (!(x == stx && y == sty)) {
                auto [xx, yy, d] = lst[x][y][dir];
                if (d == 0) {
                    ans += 'U';
                } else if (d == 1) {
                    ans += 'R';
                } else if (d == 2) {
                    ans += 'D';
                } else {
                    ans += 'L';
                }
                x = xx, y = yy, dir = d;
            }

            reverse(ans.begin(), ans.end());

            cout << ans;
            break;
        }

        int a = x + dx[dir], b = y + dy[dir];
        if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#') continue;
        if (s[a][b] == 'o') {
            if (!vis[a][b][dir]) {
                q.push({a, b, dir});
                vis[a][b][dir] = 1;
                lst[a][b][dir] = {x, y, dir};
            }
        } else if (s[a][b] == 'x') {
            for (int i = 0; i < 4; i++) {
                if (i == dir) continue;
                if (!vis[a][b][i]) {
                    q.push({a, b, i});
                    lst[a][b][i] = {x, y, dir};
                    vis[a][b][i] = 1;
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                if (!vis[a][b][i]) {
                    q.push({a, b, i});
                    lst[a][b][i] = {x, y, dir};
                    vis[a][b][i] = 1;
                }
            }
        }
    }

    if (!f) {
        cout << "No\n";
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