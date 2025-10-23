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

struct SegmentTree {
    struct E {
        int l, r, mn;
    };
    V<E>tr;
    V<int>w;
    SegmentTree (V<int>t) {
        tr.resize (4e5 + 10);
        w = t;
    }

    void pushup (int u) {
        tr[u].mn = min (tr[u << 1].mn, tr[u << 1 | 1].mn);
    }

    void build (int u, int l, int r) {
        tr[u] = { l,r,(int)1e18 };
        if (l == r) {
            tr[u].mn = w[l];
            RE;
        }
        int mid = l + r >> 1;
        build (u << 1, l, mid), build (u << 1 | 1, mid + 1, r);
        pushup (u);
    }

    void modify (int u, int x, int v) {
        if (tr[u].l == tr[u].r) {
            tr[u].mn = v;
            RE;
        }

        int mid = tr[u].l + tr[u].r >> 1;

        if (x <= mid)modify (u << 1, x, v);
        else modify (u << 1 | 1, x, v);
        pushup (u);
    }

    int query (int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l)return 1e18;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].mn;
        }
        int ans = 1e18;

        ans = min ({ ans,query (u << 1,l,r),query (u << 1 | 1,l,r) });
        return ans;
    }
};

void solve () {
    int n, q;
    cin >> n;

    V<int>idx (1, 0), w (1, 0), preidx (n + 1, 0);

    int tot = 0;

    FOR (i, 1, n) {
        int m, x;
        cin >> m;
        tot += m;
        FOR (j, 1, m) {
            cin >> x;
            w.eb (x);
        }
        idx.eb (m);
        preidx[i] = preidx[i - 1] + m;
    }

    cin >> q;
    SegmentTree A (w);
    A.build (1, 1, tot);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            int r = preidx[x - 1] + y;
            A.modify (1, r, v);
        } else {
            int x;
            cin >> x;
            cout << A.query (1, 1, preidx[x]) << endl;
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