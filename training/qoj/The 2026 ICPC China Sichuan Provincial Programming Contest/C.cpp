#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int len, x;
        cin >> len;
        while (len--) {
            cin >> x;
            g[i].push_back(x);
        }
    }
    vector<int> a(m + 1, 0);
    for (int i = 1; i <= m; i++) cin >> a[i];

    vector<int> f(1e5 + 10, 1e9);
    int ans = 0;

    vector<int> lst;

    for (int i = 1; i <= m; i++) {
        vector<int> h;

        int cur = ans + 1;

        for (auto v : g[a[i]]) {
            int cost = min(ans + 1, f[v]);
            h.push_back(cost);
            cur = min(cur, cost);
        }

        for (auto v : lst) f[v] = 1e9;

        lst = g[a[i]];

        for (int id = 0; id < h.size(); id++) {
            f[lst[id]] = h[id];
        }

        ans = cur;
    }

    cout << ans << '\n';
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