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

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    V<int> l(n + 1, 0), r(n + 1, 0);
    V<int> fat(n + 1, 0);
    V<V<int>> g(n + 1);

    fat[1] = 0;
    FOR(i, 1, n) {
        cin >> l[i] >> r[i];
        if (l[i]) fat[l[i]] = i, g[i].eb(l[i]);
        if (r[i]) fat[r[i]] = i, g[i].eb(r[i]);
    }
    if (n == 1) {
        cout << 1 << endl;
        RE;
    }

    V<int> f(n + 1, 0), isleaf(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, fa);
            f[u] += (f[v] + 2);
        }
    };

    dfs(dfs, 1, 0);

    V<int> ans(n + 1, 0), pre(n + 1, 0);

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            pre[v] = (pre[u] + f[u] + 1) % mod;
            dfs2(dfs2, v, u);
        }
    };

    dfs2(dfs2, 1, 0);

    FOR(i, 1, n) {
        cout << (pre[i] + f[i] + 1) % mod << ' ';
    }
    cout << endl;
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
