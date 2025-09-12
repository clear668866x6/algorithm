#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> lim(n + 1, -1);
    bool invalid = false;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1 && n > 1 && b == 0) {
            invalid = true;
        }
        if (lim[a] != -1 && lim[a] != b) {
            invalid = true;
        }
        lim[a] = b;
    }

    if (invalid) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(10, false));

    for (int d = 0; d <= 9; d++) {
        if (lim[n] == -1 || lim[n] == d) {
            dp[n][d] = true;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (lim[i] != -1) {
            int d = lim[i];
            if (i == 1 && n > 1 && d == 0) {
                continue;
            }
            bool found = false;
            for (int next_d = max(0, d - 1); next_d <= min(9, d + 1); next_d++) {
                if (dp[i + 1][next_d]) {
                    found = true;
                    break;
                }
            }
            dp[i][d] = found;
        } else {
            for (int d = 0; d <= 9; d++) {
                if (i == 1 && n > 1 && d == 0) {
                    continue;
                }
                bool found = false;
                for (int next_d = max(0, d - 1); next_d <= min(9, d + 1); next_d++) {
                    if (dp[i + 1][next_d]) {
                        found = true;
                        break;
                    }
                }
                dp[i][d] = found;
            }
        }
    }

    vector<int> ans(n + 1);
    int pre = -1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (lim[1] != -1) {
                if (n > 1 && lim[1] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                if (dp[1][lim[1]]) {
                    ans[1] = lim[1];
                    pre = lim[1];
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                int chosen = -1;
                for (int d = 1; d <= 9; d++) {
                    if (dp[1][d]) {
                        chosen = d;
                        break;
                    }
                }
                if (chosen == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                ans[1] = chosen;
                pre = chosen;
            }
        } else {
            int low = max(0, pre - 1);
            int high = min(9, pre + 1);
            if (lim[i] != -1) {
                int c = lim[i];
                if (c >= low && c <= high && dp[i][c]) {
                    ans[i] = c;
                    pre = c;
                } else {
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                int chosen = -1;
                for (int d = low; d <= high; d++) {
                    if (dp[i][d]) {
                        chosen = d;
                        break;
                    }
                }
                if (chosen == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                ans[i] = chosen;
                pre = chosen;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}