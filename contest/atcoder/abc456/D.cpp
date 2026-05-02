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

    vector<vector<i64>> f(n + 1, vector<i64>(3, 0));
    vector<vector<i64>> sum(n + 1, vector<i64>(3, 0));

    for (int i = 1; i <= n; i++) f[i][s[i] - 'a'] = 1;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') {
            f[i][0] = (f[i][0] + sum[i - 1][1] + sum[i - 1][2]) % mod;

        } else if (s[i] == 'b') {

            f[i][1] = (f[i][1] + sum[i - 1][0] + sum[i - 1][2]) % mod;
        } else {
            f[i][2] = (f[i][2] + sum[i - 1][0] + sum[i - 1][1]) % mod;
        }
        sum[i][0] = (sum[i - 1][0] + f[i][0]) % mod;
        sum[i][1] = (sum[i - 1][1] + f[i][1]) % mod;
        sum[i][2] = (sum[i - 1][2] + f[i][2]) % mod;
    }

    i64 tot = 0;
    for (int i = 1; i <= n; i++) tot += f[i][0], tot %= mod;
    for (int i = 1; i <= n; i++) tot += f[i][1], tot %= mod;
    for (int i = 1; i <= n; i++) tot += f[i][2], tot %= mod;
    cout << tot;
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