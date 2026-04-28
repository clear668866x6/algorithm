#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<char>> s(n + 1, vector<char>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    int idx = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && s[i][j] == '.') {
                vector<array<int, 2>> w;
                int cnt = 0;
                auto bfs = [&](int x, int y) {
                    queue<array<int, 2>> q;
                    q.push({x, y});
                    vis[x][y] = 1;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        w.push_back({x, y});

                        for (int i = 0; i < 4; i++) {
                            int a = dx[i] + x, b = dy[i] + y;
                            if (a < 1 || b < 1 || a > n || b > m || vis[a][b]) continue;
                            if (s[a][b] == '*') {
                                cnt++;
                                continue;
                            }
                            vis[a][b] = 1;
                            q.push({a, b});
                        }
                    }
                };

                bfs(i, j);
                for (auto [x, y] : w) {
                    vis[x][y] = cnt;
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << vis[x][y] << '\n';
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