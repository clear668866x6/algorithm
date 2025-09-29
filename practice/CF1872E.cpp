#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
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
    static constexpr int N = 1e5 + 10;

    struct E {
        int l, r, rev, s0, s1;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].s0 = tr[u << 1].s0 ^ tr[u << 1 | 1].s0;
        tr[u].s1 = tr[u << 1].s1 ^ tr[u << 1 | 1].s1;
    }

    void evel(int u) {
        swap(tr[u].s0, tr[u].s1);
        tr[u].rev ^= 1;
    }

    void pushdown(int u) {
        if (tr[u].rev) {
            evel(u << 1), evel(u << 1 | 1);
            tr[u].rev = 0;
        }
    }

    void build(int u, int l, int r, string &s, V<int> &w) {
        tr[u] = {l, r};
        if (l == r) {
            if (s[l] == '1') {
                tr[u] = {l, r, 0, 0, w[l]};
            } else {
                tr[u] = {l, r, 0, w[l], 0};
            }
            RE;
        }

        int mid = (l + r) >> 1;

        build(u << 1, l, mid, s, w), build(u << 1 | 1, mid + 1, r, s, w);
        pushup(u);
    }

    void modify(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            evel(u);
            RE;
        }

        pushdown(u);
        modify(u << 1, l, r);
        modify(u << 1 | 1, l, r);
        pushup(u);
    }

} A;

void solve() {
    int n, q;
    cin >> n;
    V<int> w(n + 1, 0);
    string s;
    FOR(i, 1, n) cin >> w[i];
    cin >> s;
    s = ' ' + s;
    cin >> q;
    A.build(1, 1, n, s, w);

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
            if (x == 0) {
                cout << A.tr[1].s0 << ' ';
            } else {
                cout << A.tr[1].s1 << ' ';
            }
        }
    }

    cout << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}