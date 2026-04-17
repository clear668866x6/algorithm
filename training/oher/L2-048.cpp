#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n + 2, vector<char>(m + 2, '0'));

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    vector vis(n + 2, vector(m + 2, 0));

    int ans1 = 0, ans2 = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && s[i][j] != '0') {
                bool f = false;
                auto bfs = [&](int x, int y) {
                    queue<array<int, 2>> q;
                    q.push({x, y});

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (s[x][y] != '1') {
                            f = 1;
                        }

                        for (int i = 0; i < 4; i++) {
                            int a = dx[i] + x, b = dy[i] + y;
                            if (a < 0 || b < 0 || a > n + 1 || b > m + 1 || vis[a][b] || s[a][b] == '0') continue;
                            q.push({a, b});
                            vis[a][b] = 1;
                        }
                    }
                };
                vis[i][j] = 1;
                bfs(i, j);
                ans1++;
                if (f) {
                    ans2++;
                }
            }
        }
    }

    cout << ans1 << ' ' << ans2;
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