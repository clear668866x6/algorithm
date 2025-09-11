
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