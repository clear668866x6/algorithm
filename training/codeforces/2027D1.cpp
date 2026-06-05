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

    void build(int u, int l, int r, vector<int> &val) {
        tr[u] = {l, r, (int)1e18};
        if (l == r) {
            tr[u] = {l, r, val[l]};
            return;
        }

        int mid = (l + r) / 2;
        build(u << 1, l, mid, val), build(u << 1 | 1, mid + 1, r, val);
        pushup(u);
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

    for (int i = 1; i <= n; i++) {

        SegmentTree A;

        for (int j = 1; j <= m; j++) {
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
            for (int p = r - 1; p < i; p++) {
                f[i][j] = min(f[i][j], f[p][j] + m - j);
            }

            f[i][j] = min(f[i][j], f[i][j - 1]);
        }

        for (int j = 1; j <= m; j++) {
            for (int p = 1; p < j; p++) {
                f[i][j] = min(f[i][j], f[i][p]);
            }
        }
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