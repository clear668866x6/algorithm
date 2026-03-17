# 内容
- 对于这种区间数很大的情况，并且区间的差值不会很大的情况下使用。
- 一般用埃氏筛解决：
```C++
    FOR(i, 2, n) {
        if (!npr[i]) {
            for (int j = max(2 * i, (l + i - 1) / i * i); j <= r; j += i) {
                vis[j - l] = 1;
            }

            for (int j = 2 * i; j <= n; j += i) {
                npr[j] = 1;
            }
        }
    }

```
# 题目
- abc412e
- P1835