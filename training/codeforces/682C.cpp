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

    V<V<PII>> g(n + 1);

    FOR(i, 2, n) {
        int x, c;
        cin >> x >> c;
        g[i].eb(x, c);
        g[x].eb(i, c);
    }

    V<int> d(n + 1, 0), siz(n + 1, 0);
    int ans = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = 1;
        for (auto [j, c] : g[u]) {
            if (j == fa) continue;
            d[j] = max<int>(0, d[u] + c);
            dfs(j, u);
            siz[u] += siz[j];
        }
    };

    dfs(1, 0);

    function<void(int, int)> dfs2 = [&](int u, int fa) {
        if (d[u] > w[u]) {
            ans += siz[u];
            RE;
        }
        for (auto [j, c] : g[u]) {
            if (j == fa) continue;
            dfs2(j, u);
        }
    };

    dfs2(1, 0);

    cout << ans;
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