#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    int tot = 0;
    vector<int> f(m + 1, 0);
    vector<array<int, 3>> c0, c1;

    for (int i = 1; i <= n; i++) {
        int op, t, a, b;
        cin >> op >> t >> a >> b;
        if (op == 0) {
            c0.push_back({t, a, b});
        } else {
            c1.push_back({t, a, b});
        }
        tot += t;
    }

    for (int i = 0; i < c1.size(); i++) {
        for (int j = m; j >= c1[i][1]; j--) {
            f[j] = max(f[j], f[j - c1[i][1]] + c1[i][2]);
        }
    }

    double ans = 0;

    sort(c0.begin(), c0.end(), [&](auto a, auto b) {
        double c = (a[2] * 1.0) / a[1];
        double d = (b[2] * 1.0) / b[1];
        return c > d;
    });

    for (int i = 0; i <= m; i++) {
        i64 del = m - i;
        double res = 0;
        for (int j = 0; j < c0.size(); j++) {
            if (del >= c0[j][1]) {
                del -= c0[j][1];
                res += c0[j][2];
            } else {
                res += (c0[j][2] * 1.0 / c0[j][1]) * del;
                del = 0;
                break;
            }
        }
        ans = max(ans, res + f[i]);
    }

    cout << fixed << setprecision(6) << tot - ans;
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