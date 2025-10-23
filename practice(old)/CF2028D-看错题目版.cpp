#include <algorithm>
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
    int n;
    cin >> n;

    V<V<pair<int, char>>> g(n + 1);

    V<int> j(n + 1, 0), k(n + 1, 0), q(n + 1, 0);

    FOR(i, 1, n) cin >> q[i];
    FOR(i, 1, n) cin >> k[i];
    FOR(i, 1, n) cin >> j[i];

    FORD(i, 2, n) {
        g[q[i]].pb({q[i - 1], 'q'});
        g[k[i]].pb({k[i - 1], 'k'});
        g[j[i]].pb({j[i - 1], 'j'});
    }

    V<pair<int, char>> pre(n + 1, {-1, -1});

    V<int> vis(n + 1, 0);

    bool f = false;

    function<void(int, int)> dfs = [&](int u, int fa) {
        if (vis[u] || f) RE;
        if (u == n) {
            f = 1;
            RE;
        }
        for (auto [j, w] : g[u]) {
            if (!vis[j]) {
                if (j > u) {
                    pre[j] = {u, w};
                    dfs(j, u);
                }
            }
        }
    };

    dfs(1, 0);

    if (!f) {
        NO;
    } else {
        YES;

        int t = n;
        V<pair<int, char>> ans;
        while (pre[t].fi != 1) {
            ans.pb({t, pre[t].se});
            t = pre[t].fi;
        }
        ans.pb({t, pre[t].se});

        reverse(ALL(ans));
        cout << sz(ans) << endl;
        for (auto [x, y] : ans) cout << y << ' ' << x << endl;
    }
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
