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
    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    int rt = 1;

    FOR(i, 1, n) {
        if (sz(g[i]) > sz(g[rt])) {
            rt = i;
        }
    }

    V<int> d(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto j : g[u]) {
            if (j == fa) continue;
            d[j] = d[u] + 1;
            dfs(j, u);
        }
    };

    dfs(rt, 0);

    int ans = 0;
    V<int> p;

    for (auto j : g[rt]) {
        int t = 0;
        function<void(int, int)> dfs2 = [&](int u, int fa) {
            t = max(t, d[u]);
            for (auto j : g[u]) {
                if (j == fa) continue;
                dfs2(j, u);
            }
        };
        dfs2(j, 1);
        p.eb(t);
    }

    sort(ALL(p));

    if (sz(p) == 1) {
        cout << p[0] + 1 << endl;
    } else {
        ans += (p[0] + p[sz(p) - 1]) + 1;
        FOR(i, 1, sz(p) - 2) {
            ans += (p[i]);
        }
        cout << ans << endl;
    }
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