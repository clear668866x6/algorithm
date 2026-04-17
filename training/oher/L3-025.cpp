#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), g2(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    int a, b;
    cin >> a >> b;

    int ans = 0;
    vector<int> f(n + 1, -1);

    auto dfs = [&](auto &&dfs, int u) -> int {
        if (u == b) return 1;
        if (f[u] != -1) return f[u];

        int cnt = 0;

        for (auto v : g[u]) {
            cnt += dfs(dfs, v);
        }
        return f[u] = cnt;
    };

    cout << dfs(dfs, a) << ' ';

    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(a);
    vis[a] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (auto v : g[t]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    if (!vis[b]) {
        cout << "No";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            if (!g[i].size() && i != b) {
                cout << "No";
                return;
            }
        }
    }
    if (g[b].size() > 0) {
        cout << "No";
        return;
    }
    cout << "Yes";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}