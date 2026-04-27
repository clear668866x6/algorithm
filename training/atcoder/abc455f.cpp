#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct SegmentTree {
    static constexpr int N = 2e5 + 10;
    struct E {
        int l, r;
        i64 sum, sum2, tag;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
        tr[u].sum2 = (tr[u << 1].sum2 + tr[u << 1 | 1].sum2) % mod;
    }

    void evel(int u, i64 tag) {
        tag %= mod;
        tr[u].tag += tag;
        tr[u].tag %= mod;
        int len = (tr[u].r - tr[u].l + 1);
        tr[u].sum2 += (2 * tr[u].sum * tag % mod + len * tag % mod * tag % mod) % mod;
        tr[u].sum2 %= mod;
        tr[u].sum += (len * tag) % mod;
        tr[u].sum %= mod;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0, 0};
        if (l == r) return;
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int v) {
        if (tr[u].l > r || tr[u].r < l) return;
        if (tr[u].l >= l && tr[u].r <= r) {
            evel(u, v);
            return;
        }
        pushdown(u);
        modify(u << 1, l, r, v);
        modify(u << 1 | 1, l, r, v);
        pushup(u);
    }

    array<i64, 2> query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return {0, 0};
        if (tr[u].l >= l && tr[u].r <= r) {
            return {tr[u].sum, tr[u].sum2};
        }

        pushdown(u);
        i64 ans1 = 0, ans2 = 0;
        auto [x1, x2] = query(u << 1, l, r);
        ans1 += x1, ans2 += x2;
        ans1 %= mod, ans2 %= mod;
        auto [x3, x4] = query(u << 1 | 1, l, r);
        ans1 += x3, ans2 += x4;
        ans1 %= mod, ans2 %= mod;
        return {ans1, ans2};
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;

    A.build(1, 1, n);

    auto qmi = [&](i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    i64 inv2 = qmi(2, mod - 2);

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        A.modify(1, l, r, x);
        auto [a, b] = A.query(1, l, r);
        i64 ans = (a * a % mod - b + mod) % mod * inv2 % mod;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}