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
    int n, k;
    cin >> n >> k;
    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> dep(n + 1, 0), dis(n + 1, 0);
    int id = -1;
    FOR(i, 1, n) {
        if (sz(g[i]) == 1) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        No;
        RE;
    }

    function<void(int, int)> dfs = [&](int u, int fa) {
        int mx = 0;
        dep[u] = dep[fa] + 1;
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
            mx = max(mx, dis[j]);
        }
        dis[u] = mx + 1;
    };

    dfs(id, 0);

    int rt = -1;

    FOR(i, 1, n) {
        if (sz(g[i]) >= 3 && dis[i] == k + 1) {
            if (rt != -1) {
                No;
                RE;
            }
            rt = i;
        }
    }

    if (rt == -1) {
        No;
        RE;
    }

    dfs(rt, 0);

    FOR(i, 1, n) {
        if (i == rt) continue;
        if (dep[i] <= k && sz(g[i]) - 1 < 3) {
            No;
            RE;
        }
    }

    FOR(i, 1, n) {
        if (dep[i] == k + 1 && sz(g[i]) != 1) {
            No;
            RE;
        }
    }

    Yes;
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