
struct PresidentTree {
    static constexpr int N = 2e5 + 10;
    struct E {
        int l, r, cnt;
    } tr[N * 17 + N * 5];
    int cntNode;

    PresidentTree() {
        cntNode = 0;
    }

    void modify(int &u, int v, int l, int r, int k) {
        u = ++cntNode;
        tr[u] = tr[v];
        tr[u].cnt++;
        if (l == r) RE;
        int mid = (l + r) >> 1;
        if (k <= mid)
            modify(tr[u].l, tr[v].l, l, mid, k);
        else
            modify(tr[u].r, tr[v].r, mid + 1, r, k);
    }

    int kth(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int res = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        int mid = (l + r) >> 1;
        if (k <= res)
            return kth(tr[u].l, tr[v].l, l, mid, k);
        else
            return kth(tr[u].r, tr[v].r, mid + 1, r, k - res);
    }

} A;