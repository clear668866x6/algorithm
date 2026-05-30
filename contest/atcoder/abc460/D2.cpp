#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n + 1, vector<char>(m + 1, 0));
    vector<vector<int>> d(n + 1, vector<int>(m + 1, 1e9 + 1));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    array<int, 8> dx = {0, 1, 1, 1, 0, -1, -1, -1};
    array<int, 8> dy = {1, 1, 0, -1, -1, -1, 0, 1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                for (int k = 0; k < 8; k++) {
                    int a = dx[k] + i, b = dy[k] + j;
                    if (a < 1 || b < 1 || a > n || b > m) continue;
                    if (s[a][b] == '.') {
                        q.push({0, i, j});
                        d[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    while (!q.empty()) {
        auto [dd, x, y] = q.top();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m) continue;
            if (d[a][b] > d[x][y] + 1) {
                d[a][b] = d[x][y] + 1;
                q.push({d[a][b], a, b});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] & 1) {
                cout << ".";
            } else {
                cout << "#";
            }
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