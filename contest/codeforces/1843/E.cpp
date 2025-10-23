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
struct PresidentTree {
    int cntNode = 0;
    struct E {
        int l, r, cnt;
    };

    V<E> tr;

    PresidentTree() {}
    PresidentTree(int x) {
        cntNode = 0;
        x += 10;
        tr.resize(x * 4 + 17 * x);
    }

    void modify(int &u, int v, int l, int r, int x) {
        u = ++cntNode;
        tr[u] = tr[v];
        tr[u].cnt++;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (x <= mid)
            modify(tr[u].l, tr[v].l, l, mid, x);
        else
            modify(tr[u].r, tr[v].r, mid + 1, r, x);
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
} A(2e5 + 11);

void solve() {
    int n, m;
    cin >> n >> m;

    V<array<int, 2>> w(m + 1);

    FOR(i, 1, m) cin >> w[i][0] >> w[i][1];

    int q;
    cin >> q;
    V<int> a(n + 2, n + 1), rt(n + 2, 0);
    FOR(i, 1, q) {
        int x;
        cin >> x;
        a[x] = i;
    }

    FOR(i, 1, n) A.modify(rt[i], rt[i - 1], 1, n + 1, a[i]);

    int ans = 1e18;

    FOR(i, 1, m) {
        int len = (w[i][1] - w[i][0] + 1) / 2 + 1;
        int idx = A.kth(rt[w[i][0] - 1], rt[w[i][1]], 1, n + 1, len);
        if (idx != n + 1) {
            ans = min(ans, idx);
        }
    }

    FOR(i, 1, A.cntNode + 1) {
        A.tr[i] = {0, 0, 0};
    }
    A.cntNode = 0;

    if (ans == 1e18) ans = -1;

    cout << ans << endl;
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
