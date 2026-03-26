/*
 * 算法：并查集 (Disjoint Set Union)
 * 复杂度：单次操作 O(α(n))
 * 功能：连通块维护、集合合并
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, siz;

    DSU(int n) {
        p.resize(n + 1);
        siz.assign(n + 1, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};