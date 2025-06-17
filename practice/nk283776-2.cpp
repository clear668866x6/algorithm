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
    int n;
    cin >> n;

    V<V<int>>g (4 * n + 1);
    V<string>s (4, string (n + 3, 'x'));

    FOR (i, 1, 2) {
        FOR (j, 1, n) {
            cin >> s[i][j];
        }
    }

    function<int (int, int)>get = [&] (int x, int y) {
        return (x - 1) * n + y;
        };

    array<int, 4>dx = { -1,0,1,0 }, dy = { 0,1,0,-1 };

    FOR (i, 1, 2) {
        FOR (j, 1, n) {
            if (s[i][j] == '.') {
                FOR (k, 0, 3) {
                    int a = i + dx[k], b = j + dy[k];
                    if (a<1 || b < 1 || a>2 || b>n)continue;
                    if (s[a][b] == '.') {
                        g[get (i, j)].eb (get (a, b));
                        g[get (a, b)].eb (get (i, j));
                    }
                }
            }
        }
    }

    int ans = 0, tmd = 0;

    V<int>dfn (n * 2 + 1, 0), low (n * 2 + 1, 0), vis (n * 2 + 1, 0);

    function<void (int, int)>targin = [&] (int u, int v) {
        dfn[u] = low[u] = ++tmd;
        int ch = 0;
        for (auto& j : g[u]) {
            if (!dfn[j]) {
                targin (j, u);
                low[u] = min (low[u], low[j]);
                if (low[j] >= dfn[u]) {
                    ch++;
                    if (ch > 1 || v != 0)vis[u] = 1;
                }
            } else low[u] = min (low[u], dfn[j]);
        }
        };

    FOR (i, 1, 2 * n) {
        if (!dfn[i]) {
            targin (i, 0);
        }
    }

    FOR (i, 1, 2) {
        FOR (j, 1, n) {
            if (s[i][j] == '.' && s[i - 1][j] == 'x' && s[i + 1][j] == 'x' && s[i][j - 1] == 'x' && s[i][j + 1] == 'x') {
                vis[get (i, j)] = 1;
            }
        }
    }

    FOR (i, 1, 2 * n)ans += vis[i];

    cout << ans;

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