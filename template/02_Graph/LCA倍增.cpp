/*
 * 算法：LCA 最近公共祖先 (倍增法)
 * 复杂度：预处理 O(N log N)，查询 O(log N)
 */
#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int n, max_log;
    vector<vector<int>> g, f;
    vector<int> dep;

    LCA(int n) : n(n) {
        max_log = 32 - __builtin_clz(n);
        g.resize(n + 1);
        f.assign(n + 1, vector<int>(max_log));
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

    // 默认以 1 为根
    void build(int root = 1) {
        dfs(root, 0);
    }

    int get_lca(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        for (int k = max_log - 1; k >= 0; k--) {
            if (dep[f[x][k]] >= dep[y]) x = f[x][k];
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