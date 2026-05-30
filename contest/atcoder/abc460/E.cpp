#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    i64 n, m;
    cin >> n >> m;

    string s = to_string(n);
    int len = s.size();

    i64 ans = 0;
    i128 base = 1;

    i128 lst = 0;
    for (int i = 1; i <= len; i++) {
        base *= 10;
        i128 t = base - 1;
        i128 t2 = m / gcd(m, t);
        i128 t3 = n / t2;
        i128 t4 = t - lst;
        if (i == len) {
            t4 = n - lst;
        }
        t3 %= mod, t4 %= mod;
        lst = t;

        ans = (ans + t4 * t3 % mod) % mod;
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