#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<i64> d(n + 1, 1e18);
    d[1] = 0;
    priority_queue<array<i64, 2>, vector<array<i64, 2>>, greater<array<i64, 2>>> q;
    q.push({0, 1});
    vector<int> vis(n + 1, 0);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (vis[ver]) continue;
        vis[ver] = 1;

        if (ver > 1 && d[ver - 1] > d[ver]) {
            d[ver - 1] = d[ver];
            q.push({d[ver - 1], ver - 1});
        }

        if (d[b[ver]] > d[ver] + a[ver]) {
            d[b[ver]] = d[ver] + a[ver];
            q.push({d[b[ver]], b[ver]});
        }
    }

    i64 sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (d[i] != 1e18) {
            ans = max(ans, sum - d[i]);
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