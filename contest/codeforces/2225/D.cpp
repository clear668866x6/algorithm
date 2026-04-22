#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    int n, x;
    cin >> n >> x;

    auto get = [&](int p, int mo) { return (p + (4 - mo) % 4) / 4; };

    int ans = 0;

    for (int i = 0; i < 4; i++) {
        if (i == 2 || i == 0) continue;
        int p1 = get(x, i);
        int p2 = get(x - 1, i);
        int p3 = get(n, i);
        if (i == 3) p1++, p2++, p3++;
        p1 %= mod, p2 %= mod, p3 %= mod;
        int l = p2;
        int r = (p3 - p2 + mod) % mod;
        int p = l * r % mod;
        ans += p;
        ans %= mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}