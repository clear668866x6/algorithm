#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';

    vector cnt(10, vector(10, 0));

    int d = gcd(n, 9);
    for (int i = 1; i <= n; i++) {
        cnt[(i - 1) % d][a[i] % 9]++;
    }

    vector f(d + 1, vector(10, -1e9));
    f[0][0] = 0;

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                f[i][(j + k * 9 / d) % 9] = max(f[i][(j + k * 9 / d) % 9], f[i - 1][j] + cnt[i - 1][k]);
            }
        }
    }

    cout << n - f[d][0] << '\n';
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