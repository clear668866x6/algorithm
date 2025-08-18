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
    V<int> dep;
    V<V<int>> f;
    V<V<int>> g;
    LCA() {}

    LCA(int x) {
        dep.resize(x + 10);
        f.resize(x + 10, V<int>(32));
        g.resize(x + 10);
    }

    void add(int a, int b) {
        g[a].eb(b);
        g[b].eb(a);
    }

    void dfs(int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;

        FOR(i, 1, 20) f[u][i] = f[f[u][i - 1]][i - 1];

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    }

    int lca(int a, int b) {
        if (dep[a] < dep[b]) swap(a, b);

        FORD(i, 0, 20) {
            if (dep[f[a][i]] >= dep[b]) {
                a = f[a][i];
            }
        }
        if (a == b) return a;

        FORD(i, 0, 20) {
            if (f[a][i] != f[b][i]) {
                a = f[a][i];
                b = f[b][i];
            }
        }
        return f[a][0];
    }

    int dist(int a, int b) {
        int c = lca(a, b);
        return dep[a] + dep[b] - dep[c] * 2;
    }

} A(4e5);

void solve() {
    int n;
    cin >> n;

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        A.add(a, b);
    }

    A.dfs(1, 0);

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        V<int> w(x + 1, 0);

        FOR(i, 1, x) cin >> w[i];

        int l = 0, r = 0, idl = 0, idr = 0;

        FOR(i, 1, x) {
            if (r < A.dep[w[i]]) {
                r = A.dep[w[i]];
                idr = w[i];
            }
        }

        FOR(i, 1, x) {
            int c = A.dist(idr, w[i]);
            if (l < c) {
                l = c;
                idl = w[i];
            }
        }

        bool f = false;
        int id = A.dist(idl, idr);

        FOR(i, 1, x) {
            if (A.dist(w[i], idl) + A.dist(w[i], idr) != id) {
                NO;
                f = 1;
                break;
            }
        }

        if (!f) {
            YES;
        }
    }
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
