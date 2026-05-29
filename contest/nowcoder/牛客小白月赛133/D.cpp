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

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        int t = w[i];
        for (int j = 2; j <= t / j; j++) {
            if (t % j == 0) {
                while (t % j == 0) t /= j;
                mp[j]++;
            }
        }
        if (t > 1) mp[t]++;
    }

    int ans = n;

    for (int i = 1; i <= n; i++) {
        int t = w[i];
        for (int j = 2; j <= t / j; j++) {
            if (t % j == 0) {
                while (t % j == 0) t /= j;
                ans = min(ans, n - mp[j]);
            }
        }
        if (t > 1) ans = min(ans, n - mp[t]);
    }

    if (ans == n) ans = -1;

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