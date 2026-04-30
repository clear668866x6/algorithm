#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct BIT {
    vector<int> tr;
    int n;

    BIT() {}
    BIT(int _n) : n(_n) {
        tr.resize(_n + 10, 0);
    }

    void add(int x, int v) {
        for (int i = x; i < n; i += i & -i) tr[i] += v;
    }

    i64 query(int x) {
        i64 ans = 0;
        for (int i = x; i; i -= i & -i) ans += tr[i];
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    vector<int> mx(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> w[i], mx[w[i]] = max(mx[w[i]], i);
    mx[n + 1] = n + 1;

    int l = 1, idx = 1;
    vector<array<i64, 4>> p;
    i64 tot = 0, tot2 = 0, ans = 0;
    vector<i64> tidx(n + 1, 0), ct(n + 1, 0);
    BIT A(n + 2), B(n + 2);

    while (l <= n) {
        int r = l;
        while (mx[idx] < r) {
            idx++;
        }
        r = mx[idx];
        if (r > n) break;
        i64 c = 0, c2 = 0;
        i64 len = r - l;
        if (idx != 1) {
            c2 = A.query(n + 1) - A.query(idx - 1);
        }
        i64 c3 = 0, c4 = 0;

        for (int i = l; i < r; i++) {
            if (w[i] > w[r]) {
                tot += (w[i] - w[r]);
                c3++;
                c += (w[i] - w[r]) * i;
                A.add(idx, 1), A.add(w[i] + 1, -1);
            }
        }

        cout << l << ' ' << r << ' ' << tot * r << ' ' << c << ' ' << c3 << ' ' << tot * r - c - c3 << endl;
        c3 = max(0ll, (c3 - 1) * c3 / 2);

        tot2 += (tot * r - c - c3);
        // tot2+=

        int cnt = 0, cnt2 = 0;
        for (int i = l; i < r; i++) {
            if (w[i] > w[r] - 1) {
                cnt += i;
                c4++;
                cnt2++;
            }
        }

        // cout << c4 << endl;

        c4 = max(0ll, (c4 - 1) * c4 / 2);
        p.push_back({r, cnt, c4, cnt2});

        idx++;
        l = r;
    }

    for (auto [r, cnt, c4, cnt2] : p) {
        // cout << r << ' ' << cnt2 << ' ' << cnt << ' ' << c4 << endl;
        ans = max(ans, tot2 + r * cnt2 - cnt - c4);
    }

    cout << ans << '\n';
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