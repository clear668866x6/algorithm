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
    int n;
    cin >> n;
    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> dep(n + 1, 0);
    V<double> d(n + 1, 0);

    double ans = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        dep[u] = dep[fa] + 1;
        if (u != 1 && sz(g[u]) == 1) {
            ans += (d[u] * (double)(dep[u] - 1));
        }
        int cnt = 0;
        if (fa) {
            cnt = sz(g[u]) - 1;
        } else {
            cnt = sz(g[u]);
        }
        for (auto j : g[u]) {
            if (j == fa) continue;
            d[j] = d[u] / (double)cnt;
            dfs(j, u);
        }
    };

    d[1] = 1;
    dfs(1, 0);

    cout << fixed << setprecision(12) << ans << endl;
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