#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    queue<int> q;
    q.push(1);
    vector<int> vis(n + 1, 0);
    vis[1] = 1;
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

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += vis[i];
    }

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