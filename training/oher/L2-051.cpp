#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1, 0);
    int rt = 1;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!x) {
            rt = i;
        }
        g[x].push_back(i);
        d[x]++;
        d[i]++;
        g[i].push_back(x);
    }

    int mx = 0;

    for (int i = 1; i <= n; i++) {
        mx = max(mx, d[i] - 1);
    }

    bool f = true;

    for (int i = 1; i <= n; i++) {
        if (g[i].size() != 1) {
            if (mx != d[i] - 1) {
                f = false;
            }
        }
    }

    cout << mx << ' ' << (f ? "yes" : "no") << '\n';

    vector<int> ans;

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        ans.push_back(u);
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, rt, 0);

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size() - 1];
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