#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct SegmentTree {
    int n;
    struct E {
        int l, r;
        i64 mn;
    };
    vector<E> tr;
    SegmentTree() {}
    SegmentTree(int _n) {
        n = 4 * _n;
        tr.resize(n);
    }

    void pushup(int u) {
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, (int)1e18};
        if (l == r) {
            return;
        }

        int mid = (l + r) / 2;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void modify(int u, int l, int r, i64 val) {
        if (tr[u].l > r || tr[u].r < l) return;
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].mn = min(tr[u].mn, val);
            return;
        }

        modify(u << 1, l, r, val);
        modify(u << 1 | 1, l, r, val);
        pushup(u);
    }

    i64 query(int u, int l, int r) {
        if (l > r) return 1e18;
        if (tr[u].l > r || tr[u].r < l) return 1e18;
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].mn;
        }

        i64 mn = 1e18;
        mn = min(mn, query(u << 1, l, r));
        mn = min(mn, query(u << 1 | 1, l, r));
        return mn;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int mx = *max_element(a.begin(), a.end());

    if (mx > b[1]) {
        cout << -1 << '\n';
        return;
    }

    vector<i64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    vector<vector<i64>> f(n + 1, vector<i64>(m + 1, 1e18));

    for (int i = 1; i <= m; i++) f[0][i] = 0;

    for (int j = 1; j <= m; j++) {

        SegmentTree A(n + 1);

        A.build(1, 0, n);
        A.modify(1, 0, 0, f[0][j]);

        for (int i = 1; i <= n; i++) {
            int l = 0, r = i + 1;

            auto chk = [&](int x) {
                i64 del = sum[i] - sum[max(0, x - 1)];
                return del <= b[j];
            };

            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (chk(mid))
                    r = mid;
                else
                    l = mid;
            }
            // for (int p = r - 1; p < i; p++) {
            //     f[i][j] = min(f[i][j], f[p][j] + m - j);
            // }

            f[i][j] = min(f[i][j], A.query(1, r - 1, i - 1) + m - j);

            if (j > 1) {
                f[i][j] = min(f[i][j], f[i][j - 1]);
            }
            A.modify(1, i, i, f[i][j]);
        }

        // for (int j = 1; j <= m; j++) {
        //     for (int p = 1; p < j; p++) {
        //         f[i][j] = min(f[i][j], f[i][p]);
        //     }
        // }
    }

    i64 mn = 1e18;

    for (int j = 1; j <= m; j++) mn = min(mn, f[n][j]);

    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}