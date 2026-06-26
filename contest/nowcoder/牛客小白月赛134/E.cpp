#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> d[i];
    vector<vector<array<int, 2>>> g(n + 1);
    vector<array<int, 2>> edg(m + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i] = {a, b};
    }

    int idx = -1;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << -1;
        return;
    }

    vector<int> ans(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        auto [a, b] = edg[i];
        int t = abs(d[a] - d[b]);
        ans[i] = t;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }

    vector<int> D(n + 1, 1e9);
    D[idx] = 0;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, idx});
    vector<int> vis(n + 1, 0);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (vis[ver]) continue;
        vis[ver] = 1;

        for (auto [v, w] : g[ver]) {
            if (D[v] > D[ver] + w) {
                D[v] = D[ver] + w;
                q.push({D[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (D[i] != d[i]) {
            cout << -1;
            return;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
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