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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        A.add(a, b);
    }

    A.dep[1] = 1;
    A.dfs(1, 0);

    map<int, V<int>> mp;

    FOR(i, 1, n) {
        mp[w[i]].eb(i);
    }
    V<int> ans(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto j : A.g[u]) {
            if (j == fa) continue;
            if (w[j] == w[u]) {
                ans[w[j]] = 1;
            }
            dfs(j, u);
        }
    };

    dfs(1, 0);

    FOR(i, 1, n) {
        if (ans[i]) continue;
        for (auto j : mp[i]) {
            if (ans[i]) break;
            for (auto k : mp[i]) {
                if (j == k) continue;
                if (ans[i]) break;
                int t = A.dist(j, k);
                if (t == 2) {
                    ans[i] = 1;
                    break;
                }
            }
        }
    }

    FOR(i, 1, n) cout << ans[i];
    cout << endl;

    FOR(i, 1, n) {
        A.g[i].clear();
        A.dep[i] = 0;
        FOR(k, 0, 20) {
            A.f[i][k] = 0;
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
