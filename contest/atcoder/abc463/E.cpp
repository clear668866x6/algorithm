#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<array<int, 2>>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> x(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> x[i];

    for (int i = 1; i <= n; i++) {
        g[i].push_back({0, x[i]});
        g[0].push_back({i, x[i] + y});
    }

    priority_queue<array<i64, 2>, vector<array<i64, 2>>, greater<array<i64, 2>>> q;
    vector<i64> d(n + 1, 1e18);
    d[1] = 0;
    q.push({0, 1});
    vector<int> vis(n + 1, 0);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (vis[ver]) continue;
        vis[ver] = 1;

        for (auto [v, w] : g[ver]) {
            if (d[v] > d[ver] + w) {
                d[v] = d[ver] + w;
                q.push({d[v], v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << d[i] << ' ';
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