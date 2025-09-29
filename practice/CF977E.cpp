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
    V<int> d(n + 1, 0);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
        d[a]++, d[b]++;
    }

    V<int> vis(n + 1, 0);
    V<int> c;
    int ans = 0;
    bool first = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        if (vis[u] && first) RE;
        if (vis[u] && !first) {
            first = 1;
            int t = 2;
            bool f = false;
            for (auto x : c) {
                if (t != x) {
                    f = 1;
                    break;
                }
            }
            if (!f && sz(c) > 2) {
                ans++;
            }
            RE;
        }
        vis[u] = 1;
        c.eb(d[u]);

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    };

    FOR(i, 1, n) {
        if (!vis[i]) {
            first = 0;
            c.clear();
            dfs(i, 0);
        }
    }

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