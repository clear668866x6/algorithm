#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n + 1, vector<int>(m + 1, 0));

    if (n == 1 && m == 1) {
        cout << "YES\n";
        cout << k;
        return;
    }

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                if (j & 1) {
                    ans[i][j] = 1;
                    tot++;
                } else {
                    ans[i][j] = 2;
                    tot += 2;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                if (j & 1) {
                    ans[i][j] = 2;
                    tot += 2;
                } else {
                    ans[i][j] = 1;
                    tot++;
                }
            }
        }
    }

    if (tot > k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        int del = k - tot;

        for (int i = 1; i <= n; i++) {
            bool f = false;
            for (int j = 1; j <= m; j++) {
                if (ans[i][j] == 2) {
                    ans[i][j] += del;
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << "\n";
        }
    }
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