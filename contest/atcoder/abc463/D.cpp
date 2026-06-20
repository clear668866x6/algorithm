#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    vector<int> s;
    for (auto &[x, y] : a) cin >> x >> y, s.push_back(y);

    sort(a.begin(), a.end(), [&](auto c, auto d) {
        if (c[1] == d[1]) return c[0] < d[0];
        return c[1] < d[1];
    });

    sort(s.begin(), s.end());

    int l = -1, r = 1e9 + 2;
    vector<int> f(n + 1, 0), g(n + 1, 0);

    auto chk = [&](int x) {
        for (int i = 0; i < n; i++) f[i] = g[i] = 1;

        int mx = 1;

        for (int i = 0; i < n; i++) {
            auto it = upper_bound(s.begin(), s.end(), a[i][0] - x);
            if (it != s.begin()) {
                it--;
                int del = it - s.begin();
                f[i] = max(f[i], g[del] + 1);
                mx = max(mx, f[i]);
            }
            if (i) {
                g[i] = max(g[i - 1], f[i]);
            }
        }

        return mx >= k;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (chk(mid))
            l = mid;
        else
            r = mid;
    }

    if (!l) l = -1;

    cout << l;
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