#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    map<int, vector<int>> g;

    auto dfs = [&](auto &&dfs, vector<int> a, vector<int> b, int fa) {
        if (a.size() == 1) return;
        int p = b[1];
        vector<int> c(1, 0), d(1, 0), e(1, 0), f(1, 0);
        g[p].push_back(fa);
        g[fa].push_back(p);
        int idx = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == p) {
                idx = i;
                break;
            }
        }
        for (int i = 1; i < idx; i++) {
            c.push_back(a[i]);
        }
        for (int i = 2; i <= idx; i++) {
            d.push_back(b[i]);
        }

        dfs(dfs, c, d, p);

        for (int i = idx + 1; i < a.size(); i++) {
            e.push_back(a[i]);
        }

        for (int i = idx + 1; i < b.size(); i++) {
            f.push_back(b[i]);
        }

        dfs(dfs, e, f, p);
    };

    dfs(dfs, a, b, 0);

    for (int i = 1; i <= n; i++) {
        if (g[a[i]].empty()) continue;
        reverse(g[a[i]].begin(), g[a[i]].end());
    }

    queue<int> q;
    q.push(b[1]);
    map<int, int> vis;
    vis[b[1]] = 1;
    vis[0] = 1;
    vector<int> ans;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);

        for (auto v : g[t]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

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