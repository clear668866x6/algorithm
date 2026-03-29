#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + w[i];

    vector<int> sq;

    for (int i = 0; i <= 100; i++) sq.emplace_back(i * i);

    int tot = pre[n];

    vector<vector<i64>> f(n + 1, vector<i64>(tot + 1, 1e18));

    f[0][0] = 0;

    for (int j = 0; j <= 100; j++) {
        for (int i = 1; i <= n; i++) {
            for (int s = sq[j]; s <= tot; s++) {
                f[i][s] = min(f[i][s], f[i - 1][s - sq[j]] + abs(s - pre[i]));
            }
        }
    }

    i64 ans = f[n][tot];

    if (ans == 1e18) ans = -1;

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