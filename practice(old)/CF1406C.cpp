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

    V<V<int>>g (n + 1);
    V<int>siz (n + 1, 1), dep (n + 1, 1);

    FOR (i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb (b);
        g[b].eb (a);
    }

    function<void (int, int)>dfs = [&] (int u, int fa) {
        for (auto j : g[u]) {
            if (j == fa)continue;
            dep[j] = dep[u] + 1;
            dfs (j, u);
            siz[u] += siz[j];
        }
        };

    dfs (1, 0);

    V<PII>ans;

    FOR (i, 1, n) {
        int mx = 0, tot = 0;
        if (g[i].sz == 1)continue;
        for (auto j : g[i]) {
            if (dep[i] == 1) {
                mx = max (mx, siz[j]);
            } else {
                if (dep[i] > dep[j])continue;
                mx = max (mx, siz[j]);
                tot += siz[j];
            }
        }
        if (dep[i] != 1) {
            mx = max (mx, n - 1 - tot);
        }
        ans.eb (mx, i);
    }

    sort (ALL (ans));

    if (ans.sz >= 2 && ans[0].fi == ans[1].fi) {
        int rt1 = ans[0].se, rt2 = ans[1].se;
        if (siz[rt1] < siz[rt2])swap (rt1, rt2);
        for (auto j : g[rt2]) {
            if (j == rt1)continue;
            cout << j << ' ' << rt2 << endl;
            cout << j << ' ' << rt1 << endl;
            break;
        }
    } else {
        int t = ans[0].se;
        for (auto j : g[t]) {
            cout << t << ' ' << j << endl;
            cout << t << ' ' << j << endl;
            RE;
        }
    }
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