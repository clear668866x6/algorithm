#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct SegmenTree {
    static constexpr int N = 3e5 + 10;

    struct E {
        int l, r;
        i64 sum, tag;
    } tr[N << 2];

    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void evel(int u, i64 tag) {
        tr[u].tag += tag;
        tr[u].sum += tag;
    }

    void pushdown(int u) {
        if (tr[u].tag) {
            evel(u << 1, tr[u].tag);
            evel(u << 1 | 1, tr[u].tag);
            tr[u].tag = 0;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0};
        if (l == r) return;

        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, i64 val) {
        if (tr[u].l > r || tr[u].r < l) return;
        if (tr[u].l >= l && tr[u].r <= r) {
            evel(u, val);
            return;
        }

        pushdown(u);
        modify(u << 1, l, r, val);
        modify(u << 1 | 1, l, r, val);
        pushup(u);
    }

    i64 query(int u, int l, int r) {
        if (tr[u].l > r || tr[u].r < l) return 0;
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

        i64 ans = 0;
        pushdown(u);
        ans += query(u << 1, l, r);
        ans += query(u << 1 | 1, l, r);
        return ans;
    }

} A, B;

void solve() {
    int n, q;
    cin >> n >> q;

    i64 ans = 0;

    A.build(1, 1, q);
    B.build(1, 1, q);

    vector<int> tr(n + 1, 0), tc(n + 1, 0);

    for (int i = 1; i <= q; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            int ot = tr[x];
            if (!ot) {
                ans += n;
            } else {
                ans += B.query(1, ot + 1, q);
                A.modify(1, ot, ot, -1);
            }
            tr[x] = i;
            A.modify(1, i, i, 1);
        } else {
            int ot = tc[x];
            ans -= A.query(1, ot + 1, q);
            if (ot > 0) {
                B.modify(1, ot, ot, -1);
            }
            tc[x] = i;
            B.modify(1, i, i, 1);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}