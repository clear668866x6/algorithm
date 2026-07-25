#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    vector<vector<vector<i64>>> f(n + 1, vector<vector<i64>>(4, vector<i64>(2, 0)));

    i64 ans = 0;
    for (int i = 1; i <= n; i++) f[i][1][0] = 1, ans++;

    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            f[i - 1][2][0] = 1;
            ans++;
        } else {
            f[i - 1][2][1] = 1;
            ans++;
        }
    }

    for (int len = 3; len <= n; len++) {
        int lst = (len - 2) % 3;
        int cur = len % 3;

        for (int i = 1; i <= n; i++) f[i][cur][0] = f[i][cur][1] = 0;

        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;

            if (s[l] == s[r]) {
                f[l][cur][0] += f[l + 1][lst][0];
                f[l][cur][1] += f[l + 1][lst][1];
            } else {
                f[l][cur][1] += f[l + 1][lst][0];
            }
            ans += f[l][cur][0];
            ans += f[l][cur][1];
        }
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