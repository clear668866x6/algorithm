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

    V<int> ans(n + 1, 0), num(n + 1, 0), p, vis(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        p.eb(u);
        for (auto [j, w] : g[u]) {
            if (vis[j]) {
                if ((num[j] ^ num[u]) != w) {
                    cout << -1 << endl;
                    exit(0);
                }
                continue;
            }
            vis[j] = 1;
            num[j] = w ^ num[u];

            dfs(j, u);
        }
    };

    FOR(i, 1, n) {
        if (vis[i]) continue;
        p.clear();
        num[i] = 0;
        dfs(i, 0);

        FOR(k, 0, 32) {
            int cnt = 0;
            for (auto j : p) {
                if (num[j] >> k & 1) cnt++;
            }

            if (cnt < sz(p) - cnt) {
                for (auto j : p) {
                    if (num[j] >> k & 1) {
                        ans[j] |= (1ll << k);
                    }
                }
            } else {
                for (auto j : p) {
                    if (!(num[j] >> k & 1)) {
                        ans[j] |= (1ll << k);
                    }
                }
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " ";
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