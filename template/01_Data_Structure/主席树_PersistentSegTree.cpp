/*
 * 算法：可持久化线段树 (主席树) - 静态区间第 k 小
 * 复杂度：建树 O(N log N)，单次查询 O(log N)
 */
#include <bits/stdc++.h>
using namespace std;

struct PresidentTree {
    struct Node {
        int l, r, cnt;
    };

    int n, cntNode;
    vector<Node> tr;
    vector<int> root; // root[i] 存第 i 个版本的根节点编号

    // 传入的权值范围 [1, max_val] 和 版本数量
    PresidentTree(int max_val, int max_versions) {
        n = max_val;
        cntNode = 0;
        // 经验公式：N * (4 + log N) 足够
        tr.resize(max_versions * 40 + 100);
        root.resize(max_versions + 1, 0);
    }

    // 插入一个值 v，基于旧版本 old_rt，返回新版本的根节点
    int modify(int old_rt, int l, int r, int v) {
        int u = ++cntNode;
        tr[u] = tr[old_rt]; // 复制旧节点
        tr[u].cnt++;
        if (l == r) return u;

        int mid = (l + r) / 2;
        if (v <= mid)
            tr[u].l = modify(tr[old_rt].l, l, mid, v);
        else
            tr[u].r = modify(tr[old_rt].r, mid + 1, r, v);
        return u;
    }

    // 外部调用接口
    void insert(int ver, int old_ver, int v) {
        root[ver] = modify(root[old_ver], 1, n, v);
    }

    // 查询历史版本 u 和 v 的差分树中，第 k 小的数
    int query_kth(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        // 左子树新增的个数
        int left_cnt = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        if (k <= left_cnt) {
            return query_kth(tr[u].l, tr[v].l, l, mid, k);
        } else {
            return query_kth(tr[u].r, tr[v].r, mid + 1, r, k - left_cnt);
        }
    }

    // 外部调用查询接口，查询操作区间 [L, R] 的第 k 小
    int kth(int L, int R, int k) {
        return query_kth(root[L - 1], root[R], 1, n, k);
    }
};