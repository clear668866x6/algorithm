#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n = 9;

    vector w(n + 1, vector(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    auto get = [&](int x, int y) {
        if (x <= 3 && y <= 3) return 1;
        if (x <= 6 && y <= 3) return 2;
        if (x <= 9 && y <= 3) return 3;
        if (x <= 3 && y <= 6) return 4;
        if (x <= 6 && y <= 6) return 5;
        if (x <= 9 && y <= 6) return 6;
        if (x <= 3 && y <= 9) return 7;
        if (x <= 6 && y <= 9) return 8;
        return 9;
    };

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            set<int> s1, s2, s3;
            for (int x = 1; x <= n; x++) {
                if (w[i][x] >= 1 && w[i][x] <= 9) {
                    s1.insert(w[i][x]);
                }
                if (w[x][j] >= 1 && w[x][j] <= 9) {
                    s2.insert(w[x][j]);
                }
            }

            queue<array<int, 2>> q;
            vector vis(n + 1, vector(n + 1, 0));
            q.push({i, j});
            if (w[i][j] >= 1 && w[i][j] <= 9) {
                s3.insert(w[i][j]);
            }
            vis[i][j] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int a = dx[k] + x, b = dy[k] + y;
                    if (a < 1 || b < 1 || a > n || b > n || vis[a][b] || get(a, b) != get(i, j)) continue;
                    q.push({a, b});
                    vis[a][b] = 1;
                    if (w[a][b] >= 1 && w[a][b] <= 9) {
                        s3.insert(w[a][b]);
                    }
                }
            }

            if (!(s1.size() == 9 && s2.size() == 9 && s3.size() == 9)) {
                cout << "0\n";
                return;
            }
            if (s1 != s2 && s1 != s3) {
                cout << "0\n";
                return;
            }
        }
    }

    cout << "1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}