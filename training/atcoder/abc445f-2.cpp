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
    static constexpr int N = 5e5 + 10;

    struct E {
        int l, r, len, ls, rs, mx;
    } tr[N << 2];

    string s;

    void pushup(E &u, E l, E r) {
        u.l = l.l, u.r = r.r;
        u.len = l.len + r.len;
        u.ls = l.ls, u.rs = r.rs;
        u.mx = max(l.mx, r.mx);
        if (s[l.r] == s[r.l]) {
            u.mx = max(u.mx, l.rs + r.ls);
            if (l.ls == l.len) {
                u.ls = l.ls + r.ls;
            }
            if (r.rs == r.len) {
                u.rs = r.rs + l.rs;
            }
        }
    }

    void bi(string &_s) {
        s = _s;
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, 1, 1, 1, 1};
            RE;
        }
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void modify(int u, int x, char c) {
        if (tr[u].l == tr[u].r) {
            s[tr[u].l] = c;
            RE;
        }

        int mid = (tr[u].l + tr[u].r) / 2;
        if (x <= mid)
            modify(u << 1, x, c);
        else
            modify(u << 1 | 1, x, c);
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    E query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return {0, 0, 0, 0, 0, 0};
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u];
        }

        E res;
        pushup(res, query(u << 1, l, r), query(u << 1 | 1, l, r));
        return res;
    }

} A;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = ' ' + s;
    A.bi(s);

    A.build(1, 1, n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            char x;
            cin >> i >> x;
            A.modify(1, i, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << A.query(1, l, r).mx << endl;
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