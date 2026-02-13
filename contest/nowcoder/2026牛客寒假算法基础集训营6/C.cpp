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
    static constexpr int N = 1e6 + 10;

    struct E {
        int l, r;
        int val, tag;
    } tr[N << 2];

    void pushup(int u) {
        if (!tr[u].tag) {
            tr[u].val = 1;
        } else {
            tr[u].val = tr[u << 1].val + tr[u << 1 | 1].val;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0};
        if (l == r) {
            tr[u] = {l, r, 1, 0};
            RE;
        }
        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) RE;
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].tag = 1;
            pushup(u);
            RE;
        }

        modify(u << 1, l, r);
        modify(u << 1 | 1, l, r);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].val;
        }

        int ans = 0;
        if (!tr[u].tag) {
            ans++;
        }
        ans += query(u << 1, l, r) + query(u << 1 | 1, l, r);
        return ans;
    }
} A;

void solve() {
    int n;
    cin >> n;

    A.build(1, 1, n);

    FOR(i, 1, n) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            A.modify(1, l, r);
        } else {
            cout << A.query(1, l, r) << endl;
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