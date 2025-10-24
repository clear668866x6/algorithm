
struct BIT {
    static constexpr int N = 5e5 + 10;
    int tr[N];

    void add(int x, int c) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += c;
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += tr[i];
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
        ans += (i - 1 - A.query(get(w[i])));
        A.add(get(w[i]), 1);
    }

    cout << ans;
}
