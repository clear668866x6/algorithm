#include <algorithm>
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

    V<int> a(k + 1, 0), vis(n + 1, 0), dep(n + 1, 0);

    FOR(i, 1, k) cin >> a[i], vis[a[i]] = 1;

    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    function<void(int, int)> dfs = [&](int u, int fa) {
        dep[u] = dep[fa] + 1;
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    };

    dfs(1, 0);

    int id = 0;

    FOR(i, 1, n) {
        if (vis[i]) {
            if (dep[i] > dep[id]) {
                id = i;
            }
        }
    }

    FOR(i, 1, n) dep[i] = 0;

    dfs(id, 0);

    int mx = 0;

    FOR(i, 1, n) {
        if (vis[i]) {
            mx = max(mx, dep[i]);
        }
    }

    cout << mx / 2 << endl;
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
