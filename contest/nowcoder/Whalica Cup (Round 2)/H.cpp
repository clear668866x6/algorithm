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
    static constexpr int N = 1e5 + 10;
    struct E {
        int l, r, cnt, s;
    } tr[N << 2];

    int pw[N];

    void init() {
        pw[0] = 1;
        FOR(i, 1, N - 10) pw[i] = pw[i - 1] * 2 % mod;
    }

    void pushup(int u) {
        tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
        tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s * pw[tr[u << 1].cnt]) % mod;
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, 1, l * 2 % mod};
            RE;
        }
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int x, int t) {
        if (tr[u].l == tr[u].r) {
            if (!t) {
                tr[u].cnt = tr[u].s = 0;
            } else {
                tr[u].cnt = 1;
                tr[u].s = x * 2 % mod;
            }
            RE;
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        if (x <= mid)
            modify(u << 1, x, t);
        else
            modify(u << 1 | 1, x, t);
        pushup(u);
    }

    int query(int u, int x) {
        if (tr[u].l == tr[u].r) return tr[u].cnt;
        int mid = (tr[u].l + tr[u].r) / 2;
        int ans = 0;
        if (x <= mid)
            ans += query(u << 1, x);
        else
            ans += query(u << 1 | 1, x);
        return ans;
    }

    int query2(int u) {
        if (!tr[u].cnt) return -1;
        if (tr[u].l == tr[u].r) return tr[u].l;
        if (tr[u << 1].cnt > 0) return query2(u << 1);
        return query2(u << 1 | 1);
    }

} A;

void solve() {
    int n, q;
    cin >> n >> q;
    A.init();
    A.build(1, 1, n);
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            if (A.query(1, x)) {
                A.modify(1, x, 0);
            }
        } else if (op == 2) {
            cin >> x;
            if (A.query(1, x) == 0) {
                A.modify(1, x, 1);
            }
        } else if (op == 3) {
            int t = A.query2(1);
            if (t == -1) {
                cout << n + 1 << endl;
            } else {
                cout << t << endl;
            }
        } else {
            cout << A.tr[1].s << endl;
        }
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