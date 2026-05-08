#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> g(n + 1);
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<i64>> f(n + 1, vector<i64>(2, 1e9));
    vector<vector<i64>> h(n + 1, vector<i64>(2, 1e9));
    h[1][0] = w[1];
    h[1][1] = w[1] ^ x;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        if (g[u].size() == 1) {
            f[u][0] = w[u];
            f[u][1] = (w[u] ^ x);
            return;
        }
        for (auto v : g[u]) {
            if (v == fa) continue;
            h[v][0] = dfs(dfs, v, u);
            f[u][0] = min(f[u][0], max(f[v][0], f[v][1])) + w[u];
            f[u][1] = min(f[u][1], f[v][1]) + (w[u] ^ x);
        }
    };

    dfs(dfs, 1, 0);
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