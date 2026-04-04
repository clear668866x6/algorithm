#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 676767677;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1, 0);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) cin >> b[i], mp[b[i]]++;

    vector<int> c(n + 1, 0);
    vector<int> pre(m + 1, 0);

    i64 ans = 1;

    pre[0] = mp[0];
    for (int i = 1; i < m; i++) {
        pre[i] = pre[i - 1] + mp[i];
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) continue;
        int mn = n + 1;
        if (i - 1 >= 1) mn = min(mn, b[i - 1]);
        if (i + 1 <= n) mn = min(mn, b[i + 1]);
        if (mn >= b[i]) {
            ans = 0;
            break;
        }

        if (mn == b[i] - 1) {
            ans *= pre[b[i] - 1];
        } else {
            ans *= mp[b[i] - 1];
        }

        ans %= mod;
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