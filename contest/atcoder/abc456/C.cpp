#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    i64 ans = 0, cnt = -1;

    auto qmi = [&](i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    };

    i64 inv2 = qmi(2, mod - 2);
    bool f = false;

    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 2) * (cnt + 1) % mod * inv2 % mod;
            ans %= mod;
            cnt = 0;
        }
    }

    ans += (cnt + 1) * (cnt + 2) % mod * inv2 % mod;
    ans %= mod;

    cout << ans;
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