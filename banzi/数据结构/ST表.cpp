
struct ST {
    V<V<int>> f;
    int n;
    ST() {}
    ST(int x, V<int> w) {
        f.resize(x + 10, V<int>(22, 0));
        n = x;
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = w[i];
                else
                    f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = __lg(r - l + 1);

        return gcd(f[l][len], f[r - (1 << len) + 1][len]);
    }
};
