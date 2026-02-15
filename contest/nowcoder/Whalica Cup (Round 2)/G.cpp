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
        int l, r, s, mx;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void build(int u, int l, int r, V<int> &w) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, w[l], w[l]};
            RE;
        }
        int mid = (l + r) / 2;
        build(u << 1, l, mid, w), build(u << 1 | 1, mid + 1, r, w);
        pushup(u);
    }

    int query(int u, int l, int r, int x) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].mx < x) return 0;
        if (tr[u].l == tr[u].r) {
            int val = tr[u].s;
            if (val >= x) {
                tr[u].s = tr[u].mx = 0;
                return val;
            }
            return 0;
        }
        int ans = query(u << 1, l, r, x) + query(u << 1 | 1, l, r, x);
        pushup(u);
        return ans;
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    A.build(1, 1, n, w);

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << A.query(1, l, r, x) << endl;
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