#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct Comb {
    static constexpr int N = 3e6 + 10;

    i64 fac[N], infac[N];

    i64 qmi(i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

    void init() {
        int n = N - 10;
        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) infac[i] = infac[i + 1] * (i + 1) % mod;
    }

    i64 C(int a, int b) {
        if (a < 0 || b < 0 || a - b < 0) return 0;
        return fac[a] * infac[b] % mod * infac[a - b] % mod;
    }

} A;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    A.init();

    int tot = a + b + c;

    i64 ans = 0;

    for (int i = 1; i <= b + 1; i++) {
        i64 t = A.C(b + 1, i) * A.C(a - 1, i - 1) % mod;
        int del = b + 1 - i;
        i64 t2 = A.C(c + del - 1, del - 1);
        ans += (t * t2 % mod);
        ans %= mod;
    }
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