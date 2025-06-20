#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()
//注意这个k含义是维护左端点，我们这道题只需要维护左端点即可

struct SegmentTree {
    struct E {
        int l, r, s, tag;
    };
    V<E>tr;
    V<int>w;

    SegmentTree (int x, V<int>b) {
        tr.resize (4 * x + 10);
        w = b;
    }

    void pushup (int u) {
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    void evel (int u, int tag) {
        tr[u].s = (tr[u].r - tr[u].l + 2 * tag) * (tr[u].r - tr[u].l + 1) / 2;
        tr[u].tag = tag;
    }

    void pushdown (int u) {
        if (tr[u].tag) {
            evel (u << 1, tr[u].tag);
            evel (u << 1 | 1, tr[u].tag + (tr[u << 1].r - tr[u << 1].l + 1));
            tr[u].tag = 0;
        }
    }

    void build (int u, int l, int r) {
        tr[u] = { l,r,0,0 };
        if (l == r) {
            tr[u] = { l,r,w[l],0 };
            RE;
        }
        int mid = l + r >> 1;
        build (u << 1, l, mid), build (u << 1 | 1, mid + 1, r);
        pushup (u);
    }

    void modify (int u, int l, int r, int k) {
        if (tr[u].l > r || tr[u].r < l)RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].tag = tr[u].l - l + k;
            tr[u].s = (tr[u].r - tr[u].l + 1) * (tr[u].r - tr[u].l + 2 * tr[u].tag) / 2;
            RE;
        }

        pushdown (u);
        modify (u << 1, l, r, k);
        modify (u << 1 | 1, l, r, k);
        pushup (u);//找了半天发现这个写成了pushdown
    }

    int query (int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l)return 0;
        if (tr[u].l >= l && tr[u].r <= r)return tr[u].s;

        pushdown (u);

        return (query (u << 1, l, r) + query (u << 1 | 1, l, r));
    }
};

void solve () {
    int n, q;
    cin >> n >> q;
    V<int>w (n + 1, 0);

    FOR (i, 1, n)cin >> w[i];

    SegmentTree A (2e5, w);
    A.build (1, 1, n);

    while (q--) {
        int op, l, r, k;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> k;
            A.modify (1, l, r, k);
        } else {
            cin >> l >> r;
            cout << A.query (1, l, r) << endl;
        }
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}