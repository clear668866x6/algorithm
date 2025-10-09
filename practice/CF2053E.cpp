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
    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> siz(n + 1, 0), sum(n + 1, 0);
    int cnt = 0, ans = 0;
    V<int> vis(n + 1, 0), f(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = 1;
        sum[u] = vis[u];
        f[u] = fa;

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
            siz[u] += siz[j];
            sum[u] += sum[j];
        }
    };

    FOR(i, 1, n) {
        if (sz(g[i]) == 1) {
            cnt++;
            vis[i] = 1;
            for (auto j : g[i]) {
                vis[j] = 1;
            }
        }
    }

    dfs(1, 0);

    ans = cnt * (n - cnt);

    FOR(i, 1, n) {
        if (sz(g[i]) != 1) {
            // 下面部分
            for (auto j : g[i]) {
                if (sz(g[j]) == 1 || f[i] == j || !vis[j]) continue;
                ans += (siz[j] - sum[j]);
            }
        }
        // 上面部分
        if (i != 1 && vis[f[i]] && sz(g[i]) > 1) ans += (n - siz[i] - (sum[1] - sum[i]));
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
