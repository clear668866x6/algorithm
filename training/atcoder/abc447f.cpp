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

    V<int> f(n + 1, 0);
    int ans = 0;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
            if (sz(g[v]) - 1 >= 3) {
                f[u] = max(f[u], f[v] + 1);
            } else if (sz(g[v]) - 1 == 2) {
                f[u] = max<int>(1, f[u]);
            } else {
                f[u] = max<int>(0, f[u]);
            }
        }
    };

    dfs(dfs, 1, 0);

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        if (sz(g[u]) >= 3) ans = max(ans, f[u] + 1);
        if (sz(g[u]) == 2) ans = max(ans, (int)1);

        int mx1 = 0, mx2 = 0;

        for (auto v : g[u]) {
            if (v == fa) continue;
            int t = 0;

            if (sz(g[v]) >= 4) t = max(t, f[v] + 1);
            if (sz(g[v]) == 3) t = max(t, (int)1);

            if (mx1 < t) {
                mx2 = mx1;
                mx1 = t;
            } else if (mx2 <= t) {
                mx2 = t;
            }
            dfs2(dfs2, v, u);
        }

        if (sz(g[u]) >= 4) ans = max(ans, mx1 + mx2 + 1);
    };

    dfs2(dfs2, 1, 0);

    cout << ans << endl;
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
