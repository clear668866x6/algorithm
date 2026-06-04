#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    vector<int> mn(2 * n + 2, 1e9);

    for (int d = -n; d <= n; d++) {
        for (int x = 1; x <= n; x++) {
            int y = x - d;
            if (y < 1 || y > n) continue;
            mn[d + n] = min(mn[d + n], a[x][y]);
        }
    }

    for (int d = -n; d <= n; d++) {
        if (mn[d + n] < 0) {
            ans += abs(mn[d + n]);
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