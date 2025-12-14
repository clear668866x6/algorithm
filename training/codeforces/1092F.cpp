#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> f(n + 1, 0), dep(n + 1, 0), siz(n + 1, 1), f2(n + 1, 0);
    V<int> ans(n + 1, 0);

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        f2[u] = w[u];
        for (auto j : g[u]) {
            if (j == fa) continue;
            dep[j] = dep[u] + 1;
            dfs(dfs, j, u);
            siz[u] += siz[j];
            f2[u] += f2[j];
        }
    };

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        f[u] = (dep[u] - 1) * w[u];
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs2(dfs2, j, u);
            f[u] += f[j];
        }
    };

    auto dfs3 = [&](auto &&dfs3, int u, int fa) -> void {
        for (auto j : g[u]) {
            if (j == fa) continue;
            ans[j] = ans[u] - (f2[j]) + (f2[1] - f2[j]);
            dfs3(dfs3, j, u);
        }
    };
    dep[1] = 1;
    dfs(dfs, 1, 0);
    dfs2(dfs2, 1, 0);
    ans[1] = f[1];
    dfs3(dfs3, 1, 0);

    cout << *max_element(ALL(ans)) << endl;
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