#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1, 0), p(n + 1, 0);
    vector<i64> siz(n + 1, 1);
    iota(p.begin(), p.end(), 0);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    i64 ans = 0;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
        if (c[u] == c[fa]) {
            int a = fa, b = u;
            a = find(a), b = find(b);
            ans += siz[b];
            p[b] = a;
            siz[a] += siz[b];
        }
    };

    dfs(dfs, 1, 0);

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