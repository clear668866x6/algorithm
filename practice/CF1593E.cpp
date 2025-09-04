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

    if (k >= n) {
        cout << 0 << endl;
        RE;
    }

    V<int> dep(n + 1, 0);
    V<int> d(n + 1, 0), pre(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto j : g[u]) {
            if (j == fa) continue;
            dep[j] = dep[u] + 1;
            pre[j] = u;
            dfs(j, u);
        }
    };
    dfs(1, 0);

    int l = 0, r = 0;

    FOR(i, 1, n) {
        if (dep[i] > dep[l]) {
            l = i;
        }
    }
    dep[l] = 0;
    pre[l] = 0;
    dfs(l, 0);
    r = l;
    FOR(i, 1, n) {
        if (dep[i] > dep[r]) {
            r = i;
        }
    }

    if (dep[r] <= k) {
        cout << 0 << endl;
        RE;
    }
    int t = dep[r] / 2;

    int rt = r;

    while (t--) rt = pre[rt];

    V<int> mx(n + 1, 0);

    function<int(int, int)> dfs2 = [&](int u, int fa) {
        mx[u] = dep[u];
        int ans = 1;
        for (auto j : g[u]) {
            if (j == fa) continue;
            dep[j] = dep[u] + 1;
            ans += dfs2(j, u);
            mx[u] = max(mx[u], mx[j]);
        }
        return ((mx[u] - dep[u] < k) ? 0 : ans);
    };
    dep[rt] = 0;
    cout << dfs2(rt, 0) << endl;
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
