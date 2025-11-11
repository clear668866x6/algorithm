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
    int n, m, k;
    cin >> n >> m >> k;
    V s(n + 1, V<char>(m + 1, 0));
    int sx = 0, sy = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == 'X') {
                sx = i, sy = j;
            }
        }
    }

    if (k & 1) {
        cout << "IMPOSSIBLE";
        RE;
    }

    array<int, 4> dx = {1, 0, 0, -1}, dy = {0, -1, 1, 0};
    string p = "DLRU";

    string ans;
    bool f = false;
    V<V<int>> vis(n + 1, V<int>(m + 1, 0));
    V<V<int>> d(n + 1, V<int>(m + 1, 1e18));

    auto bfs = [&](int x, int y) {
        queue<PII> q;
        q.push({x, y});
        d[x][y] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            FOR(i, 0, 3) {
                int a = dx[i] + x, b = dy[i] + y;
                if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '*') continue;
                if (d[a][b] > d[x][y] + 1) {
                    d[a][b] = d[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
    };

    bfs(sx, sy);

    function<void(int, int, int)> dfs = [&](int step, int x, int y) {
        if (step >= k) {
            f = 1;
            RE;
        }

        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '*' || d[a][b] > k - step) continue;
            ans += p[i];
            dfs(step + 1, a, b);
            if (f) RE;
        }
    };

    dfs(0, sx, sy);

    if (sz(ans) < k) {
        cout << "IMPOSSIBLE";
        RE;
    }

    cout << ans;
}

/*
特例：（一直WA49）
7 4 18
..X.
....
....
....
.**.
....
*b..


*/

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}