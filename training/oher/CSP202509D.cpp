#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct LCA {
    int n, max_log;
    vector<vector<int>> g;
    vector<array<int, 20>> f;
    vector<int> dep;

    LCA(int n) : n(n) {
        max_log = 32 - __builtin_clz(n);
        g.resize(n + 1);
        f.assign(n + 1, array<int, 20>());
        dep.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int k = 1; k < max_log; k++) {
            f[u][k] = f[f[u][k - 1]][k - 1];
        }
        for (int v : g[u]) {
            if (v != fa) dfs(v, u);
        }
    }

    void build(int root = 1) {
        dfs(root, 0);
    }

    int get_lca(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        int dif = dep[x] - dep[y];
        while (dif > 0) {
            int k = __builtin_ctz(dif);
            x = f[x][k];
            dif &= dif - 1;
        }
        if (x == y) return x;
        for (int k = max_log - 1; k >= 0; k--) {
            if (f[x][k] != f[y][k]) {
                x = f[x][k];
                y = f[y][k];
            }
        }
        return f[x][0];
    }

    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[get_lca(a, b)];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> val(n + 1, 0), pos(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> val[i], pos[val[i]] = i;

    LCA A(n);

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        A.add_edge(a, b);
    }

    A.build();
    vector<array<int, 2>> pt(n + 2, {-1, -1});

    int L = pos[0], R = pos[0];
    pt[1] = {L, R};

    for (int i = 1; i <= n; i++) {
        int z = pos[i];
        if (A.dist(L, z) + A.dist(z, R) != A.dist(L, R)) {
            if (A.dist(z, L) + A.dist(L, R) == A.dist(z, R)) {
                L = z;
            } else if (A.dist(z, R) + A.dist(L, R) == A.dist(z, L)) {
                R = z;
            } else {
                break;
            }
        }
        pt[i + 1] = {L, R};
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = n + 1;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int L = pt[mid][0], R = pt[mid][1];
            if (L == -1) {
                r = mid;
            } else {
                if (A.dist(L, x) + A.dist(L, y) == A.dist(x, y) && A.dist(R, x) + A.dist(R, y) == A.dist(x, y)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }
        cout << l << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}