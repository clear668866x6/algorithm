#include <algorithm>
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

struct SegmentTree {
    static constexpr int N = 2e5 + 10;
    struct E {
        int l, r, mx;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0};
        if (l == r) RE;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int v) {
        if (tr[u].l == tr[u].r) {
            tr[u].mx = max(tr[u].mx, v);
            RE;
        }

        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
        return max(query(u << 1, l, r), query(u << 1 | 1, l, r));
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> h(n + 1, 0), a(n + 1, 0);
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> a[i];

    V<int> f(n + 1, 0);
    A.build(1, 1, n);

    FOR(i, 1, n) {
        f[i] = A.query(1, 1, h[i] - 1) + a[i];
        A.modify(1, h[i], f[i]);
    }

    cout << f[n];
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