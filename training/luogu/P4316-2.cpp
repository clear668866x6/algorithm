#include <bits/stdc++.h>
#include <iomanip>
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
    V<V<PII>> g(n + 1);

    V<int> d(n + 1, 0);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        d[a]++;
    }

    V<double> f(n + 1, -1);

    auto dfs = [&](auto &&dfs, int u) -> double {
        if (u == n) return 0;
        if (f[u] != -1) return f[u];

        double ans = 0;

        for (auto [v, w] : g[u]) {
            ans += (dfs(dfs, v) + w * 1.) / d[u];
        }
        return f[u] = ans;
    };

    cout << fixed << setprecision(2) << dfs(dfs, 1);
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