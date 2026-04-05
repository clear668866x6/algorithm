#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << "1\n";
        return;
    }

    int ans = 0;

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

    for (int i = n; i >= 1; i--) {
        f[i][i] = 1;
        vector<int> mx(2010, 0);
        for (int j = i + 1; j <= n; j++) {
            if (j > i + 1) {
                if (!mx[2 * a[j - 1]]) mx[2 * a[j - 1]] = 1;
            }

            f[i][j] = 2 + mx[a[i] + a[j]];
            ans = max(ans, f[i][j]);

            for (int k = i + 1; k < j; k++) {
                int t = a[k] + a[j];
                mx[t] = max(mx[t], f[k][j]);
            }
        }
    }

    cout << ans << '\n';
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