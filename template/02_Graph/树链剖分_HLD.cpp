/*
 * 算法：树链剖分 (Heavy-Light Decomposition)
 * 复杂度：初始化 O(N)，修改/查询 O(log^2 N)
 * 功能：将树上路径转化为连续的 DFS 序区间 (配合线段树使用)
 */
#include <bits/stdc++.h>
using namespace std;

struct HLD {
    int n, timer;
    vector<vector<int>> g;
    // siz:子树大小, dep:深度, fa:父节点, son:重儿子
    // top:所在重链顶点, dfn:dfs序(也就是线段树里的下标), rnk:dfs序对应的原节点
    vector<int> siz, dep, fa, son, top, dfn, rnk;

    HLD(int n) : n(n), timer(0) {
        g.resize(n + 1);
        siz.assign(n + 1, 0);
        dep.assign(n + 1, 0);
        fa.assign(n + 1, 0);
        son.assign(n + 1, 0);
        top.assign(n + 1, 0);
        dfn.assign(n + 1, 0);
        rnk.assign(n + 1, 0);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs1(int u, int f, int d) {
        dep[u] = d;
        fa[u] = f;
        siz[u] = 1;
        int max_sub = -1;
        for (int v : g[u]) {
            if (v == f) continue;
            dfs1(v, u, d + 1);
            siz[u] += siz[v];
            if (siz[v] > max_sub) {
                max_sub = siz[v];
                son[u] = v;
            }
        }
    }

    void dfs2(int u, int t) {
        top[u] = t;
        dfn[u] = ++timer;
        rnk[timer] = u;
        if (!son[u]) return;
        dfs2(son[u], t); // 优先走重儿子
        for (int v : g[u]) {
            if (v != fa[u] && v != son[u]) {
                dfs2(v, v);
            }
        }
    }

    void build(int root = 1) {
        dfs1(root, 0, 1);
        dfs2(root, root);
    }

    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    // 【核心示范】：如果要求树上 u 到 v 路径的最大值，如何拆分给线段树？
    /*
    int query_path(int u, int v, SegTree &seg) {
        int ans = 0;
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ans = max(ans, seg.query(1, dfn[top[u]], dfn[u])); // 查线段树
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ans = max(ans, seg.query(1, dfn[u], dfn[v])); // 最后一段
        return ans;
    }
    */
};