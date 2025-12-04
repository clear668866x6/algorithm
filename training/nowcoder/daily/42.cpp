#include <bits/stdc++.h>
using namespace std;

// #define int int64_t
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> w(n);
    for (auto &[x, y] : w) cin >> x >> y;

    vector<array<array<int, 2>, 11>> dp(n + 1);
    vector pre(12, vector<int>(2, 0)), suf(12, vector<int>(2, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            pre[j][0] = max(pre[j - 1][0], dp[i - 1][j][0]);
            pre[j][1] = max(pre[j - 1][1], dp[i - 1][j][1]);
        }
        for (int j = 10; j >= 1; j--) {
            suf[j][0] = max(suf[j + 1][0], dp[i - 1][j][0]);
            suf[j][1] = max(suf[j + 1][1], dp[i - 1][j][1]);
        }

        for (int j = 1; j <= 10; j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            if (w[i - 1][1] == j) {
                if (w[i - 1][0] == 0) {
                    dp[i][j][0] = max(dp[i][j][0], max(pre[j - 1][1], suf[j + 1][1]) + 1);
                } else {

                    dp[i][j][1] = max(dp[i][j][1], max(pre[j - 1][0], suf[j + 1][0]) + 1);
                }
            }
            ans = max({ans, dp[i][j][0], dp[i][j][1]});
        }
        for (int j = 1; j <= 10; j++) pre[j][0] = pre[j][1] = suf[j][0] = suf[j][1] = 0;
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}