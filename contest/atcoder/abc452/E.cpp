#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<i64> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    i64 t1 = 0, t2 = 0, c1 = 0, c2 = 0;

    vector<i64> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + a[i]) % mod;

    for (int i = 1; i <= n; i++) c1 += i * a[i], c1 %= mod;
    for (int i = 1; i <= m; i++) c2 += b[i], c2 %= mod;

    t1 = (c1 * c2) % mod;

    for (int j = 1; j <= m; j++) {
        i64 c = j * b[j] % mod;
        i64 d = 0;
        for (int k = 1; k * j <= n; k++) {
            int l = k * j;
            int r = min(n, (k + 1) * j - 1);
            int len = r - l + 1;
            i64 p = (pre[r] - pre[l - 1] + mod) % mod;
            d += k * p % mod;
            d %= mod;
        }
        t2 = (t2 + c * d % mod) % mod;
    }

    cout << (t1 - t2 + mod) % mod;
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