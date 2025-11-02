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

struct LCA {
    static constexpr int N = 5e5 + 10;

    int f[N][22], dep[N];
    V<int> g[N];
    int n;

    LCA() {}
    void add(int a, int b) {
        g[a].eb(b);
        g[b].eb(a);
    }

    void dfs(int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        FOR(k, 1, 20) f[u][k] = f[f[u][k - 1]][k - 1];

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    }

    int lca(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);

        FORD(k, 0, 20) {
            if (dep[f[x][k]] >= dep[y]) {
                x = f[x][k];
            }
        }
        if (x == y) return x;

        FORD(k, 0, 20) {
            if (f[x][k] != f[y][k]) {
                x = f[x][k];
                y = f[y][k];
            }
        }
        return f[x][0];
    }

    int dist(int a, int b) {
        int t = lca(a, b);
        return dep[a] + dep[b] - 2 * dep[t];
    }
} A;

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        A.add(a, b);
    }

    A.dfs(1, 0);
    int t = A.lca(a, b);
    int cur = a;
    V<int> p1, p;
    while (cur != t) {
        p.eb(cur);
        cur = A.f[cur][0];
    }
    p.eb(t);

    cur = b;
    while (cur != t) {
        p1.eb(cur);
        cur = A.f[cur][0];
    }
    reverse(ALL(p1));

    for (auto x : p1) p.eb(x);

    if (a == b) p = {a};

    int cnt = sz(p);

    int ans = 2 * (n - 1) + (cnt - 1) / 2 + (cnt % 2 == 0);

    A.dep[p[(cnt - 1) / 2]] = 0;

    A.dfs(p[(cnt - 1) / 2], 0);

    int mx = 0;
    FOR(i, 1, n) mx = max(mx, A.dep[i]);

    ans -= mx;

    cout << ans + 1 << endl;

    FOR(i, 1, n) {
        FOR(j, 0, 21) {
            A.f[i][j] = 0;
        }
        A.dep[i] = 0;
        A.g[i].clear();
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
