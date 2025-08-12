#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
#define endl '\n'
using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

struct SegmentTree {

    struct E {
        int l, r, sum1, sum2, rev;
    };
    V<E> tr;

    SegmentTree() {}

    SegmentTree(int n) { tr.resize(4 * n + 10); }

    void pushup(int u) {
        tr[u].sum1 = tr[u << 1].sum1 ^ tr[u << 1 | 1].sum1;
        tr[u].sum2 = tr[u << 1].sum2 ^ tr[u << 1 | 1].sum2;
    }

    void pushdown(int u) {
        if (tr[u].rev) {
            tr[u << 1].rev ^= 1;
            tr[u << 1 | 1].rev ^= 1;
            swap(tr[u << 1].sum1, tr[u << 1].sum2);
            swap(tr[u << 1 | 1].sum1, tr[u << 1 | 1].sum2);
            tr[u].rev = 0;
        }
    }

    void build(int u, int l, int r, const V<int>& w, const string& s) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u] = {l, r, (s[l] == '1') ? w[l] : 0, (s[l] == '0' ? w[l] : 0), 0};
            RE;
        }

        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w, s), build(u << 1 | 1, mid + 1, r, w, s);
        pushup(u);
    }

    void modify(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l)
            RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            swap(tr[u].sum1, tr[u].sum2);
            tr[u].rev ^= 1;
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r), modify(u << 1 | 1, l, r);
        pushup(u);
    }

    int query(int u, int l, int r, int op) {
        if (tr[u].l > r || tr[u].r < l)
            return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            if (op == 1) {
                return tr[u].sum1;
            } else {
                return tr[u].sum2;
            }
        }

        pushdown(u);
        return (query(u << 1, l, r, op) ^ query(u << 1 | 1, l, r, op));
    }
} A(1e5);

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0);
    string s;
    FOR(i, 1, n) cin >> w[i];
    cin >> s;
    s = ' ' + s;

    A.build(1, 1, n, w, s);

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            A.modify(1, l, r);
        } else {
            int x;
            cin >> x;
            cout << A.query(1, 1, n, x) << ' ';
        }
    }
    cout << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
