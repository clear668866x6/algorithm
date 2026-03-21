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

    V<V<char>> s(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    V<V<int>> vis(n + 1, V<int>(m + 1, 0));

    int ans = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '.' && !vis[i][j]) {
                bool f = false;

                auto bfs = [&](int x, int y) {
                    queue<array<int, 2>> q;
                    q.push({x, y});
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        if (x == 1 || x == n || y == 1 || y == m) {
                            f = 1;
                        }

                        FOR(i, 0, 3) {
                            int a = dx[i] + x, b = dy[i] + y;
                            if (a < 1 || b < 1 || a > n || b > m || vis[a][b] || s[a][b] == '#') continue;
                            q.push({a, b});
                            vis[a][b] = 1;
                        }
                    }
                };

                bfs(i, j);
                if (!f) ans++;
                vis[i][j] = 1;
            }
        }
    }

    cout << ans;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}