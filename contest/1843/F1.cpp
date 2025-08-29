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

    V<V<int>> g(n * 2 + 2);
    V<int> w(n * 2 + 1, 0);
    w[1] = 1;
    int cnt = 1;
    V<int> mx(n * 2 + 1, 0), mn(n * 2 + 1, 0);
    mx[1] = 1;

    function<void(int, int)> dfs = [&](int u, int fa) {
        mx[u] = max(mx[u], mx[fa] + w[u]);
        mn[u] = min(mn[u], mn[fa] + w[u]);
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int fa) {
        mx[u] = max(mx[u], mx[fa]);
        mn[u] = min(mn[u], mn[fa]);

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs2(j, u);
        }
    };

    V<array<int, 2>> q;

    FOR(i, 1, n) {
        char op;
        cin >> op;
        if (op == '+') {
            int v, x;
            cin >> v >> x;
            w[++cnt] = x;
            g[v].eb(cnt);
            g[cnt].eb(v);
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            q.pb({v, x});
        }
    }

    dfs(1, 0);
    dfs2(1, 0);

    for (auto [a, b] : q) {
        if (mn[a] <= b && b <= mx[a]) {
            YES;
        } else {
            NO;
        }
    }
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
