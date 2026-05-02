#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) g[i].push_back(i);

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int w;
    cin >> w;

    vector<string> s(n + 1);
    vector<int> vis(n + 1, 0);

    vector<vector<int>> val(n + 1);

    for (int i = 1; i <= n; i++) cin >> s[i], s[i] = ' ' + s[i];

    queue<array<int, 2>> q;

    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= n; i++) {
            if (s[i][j] == 'o') {
                if (j == 1) {
                    q.push({i, 0});
                    vis[i] = 1;
                }
                val[i].push_back(j - 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) sort(val[i].begin(), val[i].end());

    auto dfs = [&](this auto &dfs, int u, int fa) -> int { if (vis[]) };

    while (!q.empty()) {
        auto [t, idx] = q.front();
        q.pop();

        if (dfs(t, 0)) {
            cout << "Yes\n";
            return;
        }
        if (vis[t] == 2 * n) break;

        for (auto v : g[t]) {
            auto it = lower_bound(val[v].begin(), val[v].end(), (idx + 1) % w);
            if (it != val[v].end() && *it == (idx + 1) % w) {
                vis[v]++;
                q.push({v, (idx + 1) % w});
            }
        }
    }
    cout << "No\n";
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