/*
 * 算法：Tarjan 全家桶 (强连通分量缩点、割点、桥)
 * 复杂度：O(V + E)
 */
#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
    int n, timer, scc_cnt;
    vector<vector<int>> g;
    vector<int> dfn, low, id, sz; // id: 所属强连通分量编号, sz: 该连通分量大小
    vector<int> stk;
    vector<bool> in_stk;

    // 割点和桥的专属结果
    vector<int> cut_vertex;
    vector<pair<int, int>> bridges;

    Tarjan(int n) : n(n), timer(0), scc_cnt(0) {
        g.resize(n + 1);
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        id.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        in_stk.assign(n + 1, false);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }
    void add_undirected_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 【操作1】：有向图求强连通分量 (SCC缩点)
    void dfs_scc(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        in_stk[u] = true;
        for (int v : g[u]) {
            if (!dfn[v]) {
                dfs_scc(v);
                low[u] = min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            scc_cnt++;
            int y;
            do {
                y = stk.back();
                stk.pop_back();
                in_stk[y] = false;
                id[y] = scc_cnt;
                sz[scc_cnt]++;
            } while (y != u);
        }
    }
    void build_scc() {
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) dfs_scc(i);
    }

    // 【操作2】：无向图求割点和桥
    void dfs_cut(int u, int fa) {
        dfn[u] = low[u] = ++timer;
        int child = 0;
        bool is_cut = false;
        for (int v : g[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                child++;
                dfs_cut(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) is_cut = true; // 割点判定
                if (low[v] > dfn[u]) bridges.push_back({u, v}); // 桥判定
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
        // 根节点特殊判定
        if (fa == 0 && child < 2) is_cut = false;
        if (is_cut) cut_vertex.push_back(u);
    }
    void build_cut() {
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) dfs_cut(i, 0);
    }
};