/*
 * 算法：FHQ Treap (无旋平衡树)
 * 复杂度：所有操作 O(log N)
 * 特点：不依赖旋转，只需 Split 和 Merge，天生支持持久化和区间操作
 */
#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(1919810);
struct FHQTreap {
    struct Node {
        int l = 0, r = 0;
        int val, pri, siz;
    };
    vector<Node> tr;
    int root = 0, cnt = 0;

    FHQTreap(int max_nodes) {
        tr.resize(max_nodes + 1);
        tr[0] = {0, 0, 0, 0, 0}; // 0号节点为空节点
    }

    int new_node(int v) {
        tr[++cnt] = {0, 0, v, (int)rnd(), 1};
        return cnt;
    }

    void pushup(int u) {
        tr[u].siz = tr[tr[u].l].siz + tr[tr[u].r].siz + 1;
    }

    // 按值分裂：<= v 的在 x，> v 的在 y
    void split(int u, int v, int &x, int &y) {
        if (!u) {
            x = y = 0;
            return;
        }
        if (tr[u].val <= v) {
            x = u;
            split(tr[u].r, v, tr[u].r, y);
        } else {
            y = u;
            split(tr[u].l, v, x, tr[u].l);
        }
        pushup(u);
    }

    // 合并：必须满足 x 树的所有值 <= y 树的所有值
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (tr[x].pri > tr[y].pri) {
            tr[x].r = merge(tr[x].r, y);
            pushup(x);
            return x;
        } else {
            tr[y].l = merge(x, tr[y].l);
            pushup(y);
            return y;
        }
    }

    void insert(int v) {
        int x, y;
        split(root, v, x, y);
        root = merge(merge(x, new_node(v)), y);
    }

    void remove(int v) {
        int x, y, z;
        split(root, v, x, z);
        split(x, v - 1, x, y); // y 树中全是 v
        if (y) y = merge(tr[y].l, tr[y].r); // 只删一个
        root = merge(merge(x, y), z);
    }

    int get_rank(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int ans = tr[x].siz + 1;
        root = merge(x, y);
        return ans;
    }

    int get_val(int k) {
        int u = root;
        while (u) {
            if (tr[tr[u].l].siz + 1 == k)
                break;
            else if (tr[tr[u].l].siz >= k)
                u = tr[u].l;
            else {
                k -= tr[tr[u].l].siz + 1;
                u = tr[u].r;
            }
        }
        return tr[u].val;
    }
};