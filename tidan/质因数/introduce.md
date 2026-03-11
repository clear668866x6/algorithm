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

# 例题
- abc445e