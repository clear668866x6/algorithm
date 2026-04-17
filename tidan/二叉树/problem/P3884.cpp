#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);

    vector<int> dep(n + 1, 0), fa(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        fa[b] = a;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int x, y;
    cin >> x >> y;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        dep[u] = dep[fa] + 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);

    int mx = *max_element(dep.begin(), dep.end());

    cout << mx << '\n';
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (dep[j] == i) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << '\n';

    int t = x;
    int c1 = 0, c2 = 0;
    vector<int> vis(n + 1, 0);
    while (t != 1) {
        c1++;
        vis[t] = 1;
        t = fa[t];
    }
    vis[1] = 1;

    int t2 = y;
    while (t2 != 1 && !vis[t2]) {
        t2 = fa[t2];
        c2++;
    }
    int p = dep[t2] - 1;

    cout << (2 * (c1 - p) + c2);
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