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
    static constexpr int N = 3e5 + 10;
    struct E {
        int l, r, s, tag;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    void evel(int u, int tag) {
        tr[u].s += (tr[u].r - tr[u].l + 1) * tag;
        tr[u].tag += tag;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0};
        if (l == r) RE;
        int mid = (tr[u].l + tr[u].r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, int val) {
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            evel(u, 1);
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r, val);
        modify(u << 1 | 1, l, r, val);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].s;
        }
        pushdown(u);

        return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    }

} A;

void solve() {
    int q;
    cin >> q;
    V<int> s(3e5 + 10, 0);

    int ans = 1;

    A.build(1, 1, 3e5);

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (!A.query(1, l, r)) {
            A.modify(1, l, r, 1);
            ans = max(r - l + 2, ans);
        }
        cout << ans << endl;
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