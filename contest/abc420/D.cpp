#include <bits/stdc++.h>
#include <functional>
#include <queue>
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

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    int sx = 0, sy = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == 'S') {
                sx = i, sy = j;
            } else if (s[i][j] == 'o') {
                s[i][j] = 0;
            } else if (s[i][j] == 'x') {
                s[i][j] = 1;
            }
        }
    }

    V<V<int>> vis(n + 1, V<int>(m + 1, 0)), vv(n + 1, V<int>(m + 1, 0));

    struct E {
        int d, x, y, t;
    };

    queue<E> q;
    V<V<V<int>>> d(n + 1, V<V<int>>(m + 1, V<int>(2, 1e18)));

    q.push({0, sx, sy, 0});
    d[sx][sy][0] = 0;

    while (sz(q)) {
        auto [dd, x, y, t] = q.front();
        q.pop();

        if (s[x][y] == 'G') {
            cout << d[x][y][t] + 1 << endl;
            RE;
        }

        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#') continue;
            if (s[a][b] >= 0 && s[a][b] <= 1) {
                if ((s[a][b] ^ t)) {
                    continue;
                }
            }
            if (s[a][b] == '?') {
                if (d[a][b][t ^ 1] > dd) {
                    d[a][b][t ^ 1] = dd;
                    q.push({dd + 1, a, b, t ^ 1});
                }
            } else {
                if (d[a][b][t] > dd) {
                    d[a][b][t] = dd;
                    q.push({dd + 1, a, b, t});
                }
            }
        }
    }

    cout << -1;
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