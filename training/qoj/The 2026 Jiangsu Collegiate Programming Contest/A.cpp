#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    i64 l = -1, r = 1e13 + 10;

    auto chk = [&](i64 x) {
        vector<array<i64, 2>> seg;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= x) {
                seg.push_back({max(0ll, b[i] - (x - a[i])), min(k, b[i] + (x - a[i]))});
            }
        }

        if (seg.empty()) return false;
        sort(seg.begin(), seg.end());

        i64 L = seg[0][0], R = seg[0][1];

        if (L > 0) return false;

        for (int i = 1; i < seg.size(); i++) {
            if (seg[i][0] <= R + 1) {
                R = max(R, seg[i][1]);
            } else {
                return false;
            }
        }

        return R >= k;
    };

    while (l + 1 < r) {
        i64 mid = (l + r) / 2;
        if (chk(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r;
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