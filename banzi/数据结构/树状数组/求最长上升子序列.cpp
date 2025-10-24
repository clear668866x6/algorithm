
/*
这里的树状数组记录的是f[i]：表示以i结尾最长上升子序列的个数。
此时我们是a[i]，要找1~a[i]-1的，然后+1

https://www.cnblogs.com/adameta/p/12469404.html



*/

struct BIT {
    static constexpr int N = 2e6 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] = max(tr[i], c);
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans = max(ans, tr[i]);
        return ans;
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    V<int> c;
    FOR(i, 1, n) cin >> w[i], c.eb(w[i]);

    sort(ALL(c));
    c.erase(unique(ALL(c)), c.end());

    auto get = [&](int x) { return lower_bound(ALL(c), x) - c.begin() + 1; };

    int ans = 0;

    FOR(i, 1, n) {
        int t = A.query(get(w[i]) - 1); // 如果是严格递增的话，这里必须要-1（要在get外面）
        A.add(get(w[i]), t + 1);
        ans = max(ans, t + 1);
    }

    cout << ans << endl;
}