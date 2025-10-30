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
    V<V<PII>> g(n + 1);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b, c);
        g[b].eb(a, c);
    }

    int ans = (1ll << 60) + 1;

    V<int> vis(n + 1, 0);

    function<void(int, int, int)> dfs = [&](int u, int fa, int s) {
        if (vis[u]) RE;
        if (u == n) {
            ans = min(ans, s);
            RE;
        }
        vis[u] = 1;

        for (auto [j, w] : g[u]) {
            if (j == fa) continue;
            dfs(j, u, s ^ w);
        }
        vis[u] = 0;
    };

    dfs(1, 0, 0);

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