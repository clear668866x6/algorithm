#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<vector<int>> sum(n + 1, vector<int>(30, 0));
    vector<vector<int>> sum2(n + 1, vector<int>(30, 0));
    vector<vector<int>> sum3(n + 1, vector<int>(30, 0));
    vector<vector<int>> mp(30);

    for (int i = 1; i <= n; i++) mp[s[i] - 'a'].push_back(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            sum[i][j] = sum[i - 1][j] + (j == s[i] - 'a');
            sum2[i][j] = sum2[i - 1][j] + (sum[i][j] * sum[i - 1][j]);
            sum3[i][j] = sum3[i - 1][j] + sum[i][j];
        }
    }
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (x == 1) {
            cout << r - l + 1 << '\n';
        } else if (x == 2) {
            i64 ans = 0;
            for (int j = 0; j < 30; j++) {
                int p = sum[r][j] - sum[l - 1][j];
                ans += p * (p - 1) / 2;
            }
            cout << ans << '\n';
        } else {
            int ans = 0;
            for (int j = 0; j < 30; j++) {
                int p1 = sum[r][j] * (sum3[r - 1][j] - sum3[max(0ll, l - 2)][j]);
                int p2 = sum[l - 1][j] * (sum3[r][j] - sum3[l - 1][j]);
                int p3 = sum[r][j] * sum[l - 1][j] * (r - l + 1);
                int p4 = sum2[r][j] - sum2[l - 1][j];
                ans += (p1 + p2);
                ans -= p3;
                ans -= p4;
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}