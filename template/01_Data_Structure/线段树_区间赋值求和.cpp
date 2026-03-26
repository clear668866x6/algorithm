/*
* 算法：线段树 (区间赋值 + 区间求和)


*/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

constexpr int mod = 998244353;

struct SegmentTree {
    static constexpr int N = 2e5 + 10;

    struct E {
        int l, r, s, tag;
    } tr[N << 2];

    void pushup(int u) {
        (tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s) %= mod;
    }

    void evel(int u, int tag) {
        tr[u].tag = tag;
        tr[u].s = (tr[u].r - tr[u].l + 1) * tag;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    void build(int u, int l, int r, V<int> &w) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, w[l], 0};
            RE;
        }

        int mid = (l + r) / 2;
        build(u << 1, l, mid, w), build(u << 1 | 1, mid + 1, r, w);
        pushup(u);
    }

    void modify(int u, int l, int r, int v) {
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].tag = v;
            tr[u].s = (tr[u].r - tr[u].l + 1) * v;
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r, v);
        modify(u << 1 | 1, l, r, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }

        pushdown(u);
        return (query(u << 1, l, r) + query(u << 1 | 1, l, r)) % mod;
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    A.build(1, 1, n, w);

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int tot = A.query(1, l, r);
        int nw = tot * qmi(len, mod - 2) % mod;
        A.modify(1, l, r, nw);
    }

    FOR(i, 1, n) {
        cout << A.query(1, i, i) << ' ';
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}