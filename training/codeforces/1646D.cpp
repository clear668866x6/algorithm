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
    V<int> d(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
        d[a]++, d[b]++;
    }

    if (n == 2) {
        cout << "2 2" << endl;
        cout << "1 1";
        RE;
    }

    V<V<int>> f(n + 1, V<int>(2, 0)), f2(n + 1, V<int>(2, 0));
    V<int> ok(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
        f[u][0] = 0, f[u][1] = 1;
        f2[u][0] = 1, f2[u][1] = d[u];
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
            int t = 1;
            if (f[j][0] != f[j][1]) {
                if (f[j][0] < f[j][1])
                    t = 1;
                else
                    t = 0;
            } else {
                if (f2[j][0] < f2[j][1])
                    t = 0;
                else
                    t = 1;
            }
            ok[j] = t;
            f[u][1] += f[j][0];
            f[u][0] += f[j][t];
            f2[u][1] += f2[j][0];
            f2[u][0] += f2[j][t];
        }
    };

    dfs(1, 0);

    int t = 1;
    if (f[1][0] != f[1][1]) {
        if (f[1][0] < f[1][1])
            t = 1;
        else
            t = 0;
    } else {
        if (f2[1][0] < f2[1][1])
            t = 0;
        else
            t = 1;
    }

    cout << f[1][t] << ' ' << f2[1][t] << endl;

    V<int> ans(n + 1, 1);

    function<void(int, int, int)> dfs2 = [&](int u, int fa, int p) {
        if (p) {
            ans[u] = d[u];
        }

        for (auto j : g[u]) {
            if (j == fa) continue;
            if (!p) {
                dfs2(j, u, ok[j]);

            } else {
                dfs2(j, u, 0);
            }
        }
    };

    if (t) {
        dfs2(1, 0, 1);
    } else {
        dfs2(1, 0, 0);
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