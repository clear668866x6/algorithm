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
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    V<V<int>>g (n + 1);

    FOR (i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb (b);
        g[b].eb (a);
    }

    FOR (i, 1, n) {
        sort (ALL (g[i]));
    }

    V<int>vis (n + 1, 0);
    V<int>path (1, x);
    vis[x] = 1;

    while (path.back () != y) {
        int u = path.back ();
        V<bool>p (n + 1, 0);

        queue<int>q;
        q.push (y);
        p[y] = 1;

        while (q.sz) {
            int t = q.front ();
            q.pop ();

            for (auto j : g[t]) {
                if (!vis[j] && !p[j]) {
                    p[j] = 1;
                    q.push (j);
                }
            }
        }

        int ne = -1;

        for (auto j : g[u]) {
            if (!vis[j] && p[j]) {
                ne = j;
                break;
            }
        }

        if (ne == -1)break;

        path.eb (ne);
        vis[ne] = 1;
    }

    for (auto x : path)cout << x << ' ';
    cout << endl;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}