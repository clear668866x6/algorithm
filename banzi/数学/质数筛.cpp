
struct Zhishu {
    static constexpr int N = 1e7 + 10;

    int mu[N], vis[N], primes[N], sum[N];
    int cnt;
    Zhishu() {
        cnt = 0;
        mu[1] = 1;
        int n = 1e7;
        FOR(i, 2, n) {
            if (!vis[i]) primes[cnt++] = i, mu[i] = -1;
            for (int j = 0; i * primes[j] <= n; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0) break;
                mu[i * primes[j]] = -mu[i];
            }
        }
        FOR(i, 1, n) sum[i] = sum[i - 1] + mu[i];
    }

} A;