# 说明
- 对于质因数分解如果很多测试用例的情况下，会容易超时，所以可以采用最小因子除数法，也就是这么写：
预处理
```
    void init() {
        int n = N - 10;
        FOR(i, 2, n) {
            FOR2(j, i, n, i) {
                if (!minp[j]) minp[j] = i;
            }
        }
    }
```

计算
```
    FOR(i, 1, n) {
        int t = w[i];
        int res = ans;
        while (t > 1) {
            int p = A.minp[t], cnt = 0;
            while (t % p == 0) t /= p, cnt++;
        }
    }
```
- 可以用线性筛来预处理一个数质因子的个数，注意i%p[j]!=0说明i没有p[j]的因子，然后如果i有p[j]的因子，此时就得break，因为一个数只能被筛一次。
```C++

struct Prime {
    static constexpr int N = 1e6 + 10;

    int p[N], cnt;
    bool vis[N];
    int pn[N];
    set<int> s;

    void init() {
        int n = N - 10;

        FOR(i, 2, n) {
            if (!vis[i]) p[cnt++] = i, pn[i] = 1;
            for (int j = 0; i * p[j] <= n; j++) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) {
                    pn[i * p[j]] = pn[i];
                    break;
                } else {
                    pn[i * p[j]] = pn[i] + 1;
                }
            }
        }

        FOR(i, 1, n) {
            if (pn[i] == 2) {
                s.insert(i);
            }
        }
    }
} A;
```

# 例题
- abc445e
- abc400e