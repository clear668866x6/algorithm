
struct BitTree {
    V<int>tr;
    int n;

    BitTree (int x) {
        tr.resize (x + 10);
        n = x;
    }

    void add (int x, int c) {
        for (int i = x;i < n;i += lowbit (i))tr[i] = max (tr[i], c);
    }

    int query (int x) {
        int ans = 0;
        for (int i = x;i;i -= lowbit (i))ans = max (tr[i], ans);
        return ans;
    }

    int calc (V<int>w) {
        int ans = 0;
        FOR (i, 1, n) {
            int t = query (w[i]) + 1;
            ans = max (ans, t);
            add (w[i], t);
        }
        return ans;
    }
};