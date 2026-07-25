#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {

    int n;
    cin >> n;
    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<i64> s1(n + 1, 0), s2(n + 1, 0), s3(n + 2, 0);

    for (int i = 1; i <= n; i++) s1[i] = (s1[i - 1] + a[i]) % mod;
    for (int i = 1; i <= n; i++) s2[i] = (s2[i - 1] + i * a[i] % mod) % mod;
    for (int i = n; i >= 1; i--) s3[i] = (s3[i + 1] + (n - i + 1) * a[i] % mod) % mod;

    auto qmi = [&](i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        int mx = max(1, min(i, n - i + 1));

        int l = mx;
        int r = max(l + 1, n - mx + 1);

        i64 fz = ((s2[l] + s3[r]) % mod + mx * (s1[r - 1] - s1[l] + mod) % mod) % mod;
        i64 tot = qmi(i, mod - 2);
        ans = (ans + fz * tot % mod) % mod;
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