#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    int ans = -1e9;

    vector<int> mn1(n + 1, 1e9), mn2(n + 2, 1e9);

    for (int i = 1; i <= n; i++) mn1[i] = min(mn1[i - 1], w[i] - i);
    for (int i = n; i >= 1; i--) mn2[i] = min(mn2[i + 1], w[i] + i);

    for (int i = 1; i <= n; i++) {
        ans = max(ans, w[i] - i - mn1[i]);
        ans = max(ans, w[i] + i - mn2[i]);
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