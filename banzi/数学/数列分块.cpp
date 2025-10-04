struct FenKuai {
    int mod = 1e9 + 7;
    void work() {
        for (int l = 1; l <= m; l = r + 1) {
            if (n / l == 0)
                r = m;
            else
                r = min(m, n / (n / l));
            ans =
                (ans - ((l + r) % mod) * ((r - l + 1) % mod) % mod * ((mod + 1) / 2) % mod * (n / l) % mod + mod) % mod;
        }
    }
}
