#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    i128 l = 0, r = 3e18 + 2;

    auto chk = [&](i128 x) {
        i128 tot = 0;
        for (int i = 1; i <= n; i++) {
            if (w[i] < x) {
                tot += (x - w[i] + i - 1) / i;
            }
        }
        return tot <= k;
    };

    while (l + 1 < r) {
        i128 mid = (l + r) / 2;
        if (chk(mid))
            l = mid;
        else
            r = mid;
    }

    for (int i = 1; i <= n; i++) {
        if (w[i] < l) {
            i128 t = (l - w[i] + i - 1) / i * i;
            w[i] += t;
        }
    }

    cout << *min_element(w.begin() + 1, w.end());
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