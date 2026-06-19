#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    i64 l = 0, r = 1e18 + 10;

    auto chk = [&](i64 x) {
        if (n & 1) {
            i64 mx1 = 0;
            for (int i = 0; i <= n; i += 2) {
                if (i) {
                    mx1 = max(mx1, a[i] - a[i - 1]);
                }
                i64 mx2 = 0;
                for (int j = i + 3; j <= n; j += 2) {
                    mx2 = max(mx2, a[j] - a[j - 1]);
                }
                if (max(mx1, mx2) <= x) {
                    return 1;
                }
            }
            return 0;

        } else {
            for (int i = 2; i <= n; i += 2) {
                if (a[i] - a[i - 1] > x) {
                    return 0;
                }
            }
            return 1;
        }
    };

    while (l + 1 < r) {
        i64 mid = (l + r) / 2;
        if (chk(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << '\n';
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