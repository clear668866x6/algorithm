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

struct PresidentTree {
    static constexpr int N = 1e6 + 10;
    struct E {
        int l, r, cnt;
    } tr[N * 17 + N * 5];
    int cntNode;

    PresidentTree() {
        cntNode = 0;
    }

    void modify(int &u, int v, int l, int r, int k) {
        u = ++cntNode;
        tr[u] = tr[v];
        tr[u].cnt++;
        if (l == r) RE;
        int mid = (l + r) >> 1;
        if (k <= mid)
            modify(tr[u].l, tr[v].l, l, mid, k);
        else
            modify(tr[u].r, tr[v].r, mid + 1, r, k);
    }

    int kth(int u, int v, int l, int r, int k) {
        if (l == r) return l;
        int res = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        int mid = (l + r) >> 1;
        if (k <= res)
            return kth(tr[u].l, tr[v].l, l, mid, k);
        else
            return kth(tr[u].r, tr[v].r, mid + 1, r, k - res);
    }

    int query(int u, int v, int l, int r) {
        if (tr[v].cnt - tr[u].cnt < 2) return 0;
        if (l == r) return 1;
        int ans = 0;
        int mid = (l + r) >> 1;
        ans += query(tr[u].l, tr[v].l, l, mid);
        ans += query(tr[u].r, tr[v].r, mid + 1, r);
        return ans;
    }

} A;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> rt(n + 1, 0);

    FOR(i, 1, n) A.modify(rt[i], rt[i - 1], 1, m, w[i]);

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << A.query(rt[l - 1], rt[r], 1, m) << endl;
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