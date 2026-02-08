#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n, m;
    cin >> n >> m;
    V<V<int>> w(n + 1, V<int>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    array<int, 2> dx = {0, 1}, dy = {1, 0};

    V<V<V<int>>> d1(n + 1, V<V<int>>(m + 1, V<int>(2, -1e18)));

    auto dijistra = [&](V<V<V<int>>> &d, int sx, int sy) {
        priority_queue<array<int, 4>> q;
        d[sx][sy][0] = w[sx][sy];
        d[sx][sy][1] = -w[sx][sy];
        q.push({d[sx][sy][0], sx, sy, 0});
        q.push({d[sx][sy][1], sx, sy, 1});
        V<V<int>> vis(n + 1, V<int>(m + 1, 0));
        while (!q.empty()) {
            auto [dd, x, y, state] = q.top();
            q.pop();

            if (vis[x][y]) continue;
            vis[x][y] = 1;

            FOR(i, 0, 1) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 1 || b < 1 || a > n || b > m) continue;
                if (d[a][b][state] < d[x][y][state] + w[x][y]) {
                    d[a][b][state] = d[x][y][state] + w[x][y];
                    q.push({d[a][b][state], a, b, state});
                }

                if (state == 0) {
                    if (d[a][b][1] < d[x][y][0] - w[x][y]) {
                        d[a][b][1] = d[x][y][0] - w[x][y];
                        q.push({d[a][b][1], a, b, 1});
                    }
                }
            }
        }
    };

    dijistra(d1, 1, 1);

    int ans = max(d1[n][m][0], d1[n][m][1]);

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
