#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    int n;
    cin >> n;

    int ans = 1e18, ansl = 0, ansr = 0;

    int t = 1;
    for (int x = 1; x <= 18; x++) {
        if (x == 1) {
            ans = n;
            ansl = ansr = 1;
            continue;
        }
        if (x == 2) {
            t *= x;
            continue;
        }
        t *= x;
        for (int y = max<int>(1, n / (t - 1) - 20); y <= n / (t - 1) + 20; y++) {
            int a = abs(t * y - y - n);
            if (ans > a && y != 2) {
                ans = a;
                ansl = x, ansr = y;
            }
        }
    }
    cout << ansl << ' ' << ansr;
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