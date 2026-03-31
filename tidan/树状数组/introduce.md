# 内容
- 树状数组可以用来找第k大的数字，就是类似值域树状数组。
```C++
struct BIT {
    static constexpr int N = 5e5 + 10;

    i64 tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += i & (-i)) tr[i] += c;
    }

    int find(int p) {
        int pos = 0;
        for (int k = 19; k >= 0; k--) {
            if (pos + (1 << k) < N && tr[pos + (1 << k)] < p) {
                pos += (1 << k);
                p -= tr[pos];
            }
        }
        return pos + 1;
    }

} A;

```

# 题目
abc449e