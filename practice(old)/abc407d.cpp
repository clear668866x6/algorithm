#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n, m;
    cin >> n >> m;

    V<V<int>>w (n + 2, V<int> (m + 2, 0)), vis (n + 2, V<int> (m + 2, 0));

    int t = 0, ans = 0;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
            t ^= w[i][j];
        }
    }

    function<void (int, int, int)>dfs = [&] (int x, int y, int v) {
        if (x > n) {
            ans = max (ans, v);
            RE;
        }

        if (y - 1 >= 1 && !vis[x][y - 1]) {
            vis[x][y - 1] = vis[x][y] = 1;
            if (y == m) {
                dfs (x + 1, 1, v ^ w[x][y - 1] ^ w[x][y]);
            } else {
                dfs (x, y + 1, v ^ w[x][y - 1] ^ w[x][y]);
            }
            vis[x][y - 1] = vis[x][y] = 0;
        }

        if (x - 1 >= 1 && !vis[x - 1][y]) {
            vis[x - 1][y] = vis[x][y] = 1;
            if (y == m) {
                dfs (x + 1, 1, v ^ w[x - 1][y] ^ w[x][y]);
            } else {
                dfs (x, y + 1, v ^ w[x - 1][y] ^ w[x][y]);
            }
            vis[x - 1][y] = vis[x][y] = 0;
        }
        if (y == m) {
            dfs (x + 1, 1, v);
        } else {
            dfs (x, y + 1, v);
        }
        };

    dfs (1, 1, t);

    cout << ans << endl;


}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}