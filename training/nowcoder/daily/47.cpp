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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<int> is_fa(n + 1, 0);

    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        is_fa[b] = 1;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<V<int>> f(n + 1, V<int>(2, 0));

    int rt = 1;

    FOR(i, 1, n) {
        if (!is_fa[i]) {
            rt = i;
            break;
        }
    }

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        f[u][1] = w[u];

        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
            f[u][1] += f[v][0];
            f[u][0] += max(f[v][1], f[v][0]);
        }
    };

    dfs(dfs, rt, 0);

    cout << max(f[rt][0], f[rt][1]);
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