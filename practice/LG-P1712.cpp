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
        int l, r, mx, tag;
    };

    V<E>tr;

    SegmentTree (int x) {
        tr.resize (4 * x + 10);
    }

    void pushup (int u) {
        tr[u].mx = max (tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void pushdown (int u) {
        if (tr[u].tag) {
            tr[u << 1].tag += tr[u].tag;
            tr[u << 1 | 1].tag += tr[u].tag;
            tr[u << 1].mx += tr[u].tag;
            tr[u << 1 | 1].mx += tr[u].tag;
            tr[u].tag = 0;
        }
    }

    void build (int u, int l, int r) {
        tr[u] = { l,r };
        if (l == r)RE;
        int mid = l + r >> 1;
        build (u << 1, l, mid), build (u << 1 | 1, mid + 1, r);
    }

    void modify (int u, int l, int r, int v) {
        if (tr[u].l > r || tr[u].r < l)RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].tag += v;
            tr[u].mx += v;
            RE;
        }
        pushdown (u);
        modify (u << 1, l, r, v);
        modify (u << 1 | 1, l, r, v);
        pushup (u);
    }
};

void solve () {
    int n, m;
    cin >> n >> m;

    struct E {
        int l, r, len;
        bool operator<(const E& t)const {
            return len < t.len;
        }
    };

    V<E>w (n + 1);
    V<int>d;

    FOR (i, 1, n) {
        cin >> w[i].l >> w[i].r;
        w[i].len = w[i].r - w[i].l;
        d.eb (w[i].l);
        d.eb (w[i].r);
    }
    sort (w.begin () + 1, w.end ()), sort (ALL (d));

    d.erase (unique (ALL (d)), d.end ());

    int mn = 1e18, mx = -1e18;

    FOR (i, 1, n) {
        w[i].l = lower_bound (ALL (d), w[i].l) - d.begin () + 1;
        w[i].r = lower_bound (ALL (d), w[i].r) - d.begin () + 1;
        mn = min (mn, w[i].l);
        mx = max (mx, w[i].r);
    }

    SegmentTree A (5e5);

    A.build (1, mn, mx);

    int l = 1, ans = 1e18;

    FOR (i, 1, n) {
        A.modify (1, w[i].l, w[i].r, 1);
        while (A.tr[1].mx >= m) {
            ans = min (ans, w[i].len - w[l].len);
            A.modify (1, w[l].l, w[l].r, -1);
            l++;
        }
    }

    if (ans == 1e18)ans = -1;
    cout << ans;

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