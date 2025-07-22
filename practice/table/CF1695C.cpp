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

    V<V<int>>w (n + 1, V<int> (m + 1, 0)), vis (n + 1, V<int> (m + 1, 0));

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
        }
    }

    array<int, 2>dx = { 0,1 }, dy = { 1,0 };

    function<void (int, int, int)>dfs = [&] (int x, int y, int v) {
        if (x == n && y == m) {
            cout << v << endl;
            RE;
        }

        FOR (i, 0, 1) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a<1 || b<1 || a>n || b>m || vis[a][b])continue;
            vis[a][b] = 1;
            dfs (a, b, v + w[a][b]);
            vis[a][b] = 0;
        }
        };

    dfs (1, 1, w[1][1]);

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