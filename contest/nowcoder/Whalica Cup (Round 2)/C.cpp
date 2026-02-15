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
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n + 1);
    V<int> w(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }
    map<int, V<int>> bt;

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        bt[a].eb(b);
    }

    V<int> dep(n + 1, 0), fa(n + 1, 0);
    int mx = 0;
    auto dfs = [&](auto &&dfs, int u, int f) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        mx = max(mx, dep[u]);
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    for (auto [u, y] : bt) {
        for (auto t : y) {
            if (mx - dep[u] <= t) {
                w[u]++;
            }
        }
    }

    V<V<int>> d(n + 1, V<int>(2, 0));

    V<int> f(n + 1, 0), f2(n + 1, 0);

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        f[u] = max(f[u], f[fa] + w[u]);
        int t = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;

            dfs2(dfs2, v, u);
            t = max(t, f2[v]);
        }
        f2[u] = max(f2[u], t + w[u]);
    };

    dfs2(dfs2, 1, 0);

    map<int, V<int>> mp;
    int ans = 0;
    FOR(i, 1, n) {
        mp[dep[i]].eb(i);
    }
    V<int> mxx(mx + 2, 0);

    FOR(i, 1, n) {
        mxx[dep[i]] = max(mxx[dep[i]], f2[i]);
    }

    FOR(i, 1, n) {
        int t = dep[i];
        ans = max(ans, f[i] + mxx[t + 1]);
    }

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
