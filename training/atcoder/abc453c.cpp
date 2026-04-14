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

    int ans = 0;

    auto dfs = [&](auto &&dfs, int u, int cnt, double cur) -> void {
        if (u > n) {
            ans = max(ans, cnt);
            return;
        }

        if (cur < 0 && cur + a[u] > 0) {
            dfs(dfs, u + 1, cnt + 1, cur + a[u]);
        } else {
            dfs(dfs, u + 1, cnt, cur + a[u]);
        }

        if (cur > 0 && cur - a[u] < 0) {
            dfs(dfs, u + 1, cnt + 1, cur - a[u]);
        } else {
            dfs(dfs, u + 1, cnt, cur - a[u]);
        }
    };

    dfs(dfs, 1, 0, 0.5);

    cout << ans;
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