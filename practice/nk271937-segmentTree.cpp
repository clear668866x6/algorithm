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
        int l, r, s1, s2, s;
        int lazy1, lazy2;
    };

    V<E>tr;
    string a, b;
    void init (string x, string y) {
        tr.resize (4e5 + 10);
        a = x, b = y;
    }

    void pushup (int u) {
        tr[u].s1 = tr[u << 1].s1 + tr[u << 1 | 1].s1;
        tr[u].s2 = tr[u << 1].s2 + tr[u << 1 | 1].s2;
        tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    }

    void evel1 (int u) {
        tr[u].s1 = tr[u].r - tr[u].l + 1;
        tr[u].s = tr[u].s2;
        tr[u].lazy1 = 1;
    }

    void evel2 (int u) {
        tr[u].s2 = tr[u].r - tr[u].l + 1;
        tr[u].s = tr[u].s1;
        tr[u].lazy2 = 1;
    }

    void pushdown (int u) {
        if (tr[u].lazy1) {
            evel1 (u << 1);
            evel1 (u << 1 | 1);
            tr[u].lazy1 = 0;
        }

        if (tr[u].lazy2) {
            evel2 (u << 1);
            evel2 (u << 1 | 1);
            tr[u].lazy2 = 0;
        }
    }

    void build (int u, int l, int r) {
        tr[u] = { l,r };
        if (l == r) {
            tr[u].s1 = (a[l] == '1');
            tr[u].s2 = (b[l] == '1');
            tr[u].s = ((a[l] == '1') && (b[l] == '1'));
            RE;
        }

        int mid = l + r >> 1;
        build (u << 1, l, mid), build (u << 1 | 1, mid + 1, r);
        pushup (u);
    }

    void modify (int u, int l, int r, char c) {
        if (tr[u].l > r || tr[u].r < l)RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            if (c == 'A') {
                evel1 (u);
            } else {
                evel2 (u);
            }
            RE;
        }

        pushdown (u);
        modify (u << 1, l, r, c);
        modify (u << 1 | 1, l, r, c);
        pushup (u);
    }
}A;

void solve () {
    int n, q;
    string a, b;
    cin >> n >> a >> b >> q;
    a = ' ' + a, b = ' ' + b;

    A.init (a, b);
    A.build (1, 1, n);

    while (q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        A.modify (1, l, r, c);
        cout << (A.tr[1].s) << endl;
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