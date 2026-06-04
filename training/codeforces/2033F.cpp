#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr i64 mod = 1e9 + 7;

void solve() {
    i64 n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n % mod << '\n';
        return;
    }

    i64 t1 = 1, t2 = 1;
    for (int i = 3; i <= 10 * k; i++) {
        i64 tmp = (t1 + t2) % k;
        t1 = t2;
        t2 = tmp;
        if (t2 == 0) {
            i64 ans = (i + (i128)(n - 1) % mod * i % mod) % mod;
            cout << ans << '\n';
            break;
        }
    }
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