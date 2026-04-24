#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<i64> c1(n + 1, 0), c2(n + 1, 0);

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') {
            for (auto v : g[i]) {
                if (v == i) continue;
                if (s[v] == 'C') {
                    c1[i]++;
                }
            }
        }
        if (s[i] == 'C') {
            for (auto v : g[i]) {
                if (v == i) continue;
                if (s[v] == 'S') {
                    c2[i]++;
                }
            }
        }
    }

    i64 ans = 0;

    auto dfs2 = [&](auto &&dfs2, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs2(dfs2, v, u);
            if (s[u] == 'C' && s[v] == 'P' && s[fa] == 'C') {
                ans += (c2[fa] * (c1[v] - 1));
            }
            if (s[u] == 'C' && s[v] == 'C' && s[fa] == 'P') {
                ans += ((c1[fa] - 1) * c2[v]);
            }
        }
        i64 t1 = 0, t2 = 0;

        if (s[u] == 'C') {
            for (auto v : g[u]) {
                if (v == fa) continue;
                if (s[v] == 'C') {
                    t2 += (c2[v]);
                } else if (s[v] == 'P') {
                    t1 += (c1[v] - 1);
                }
            }
            ans += t1 * t2;
        }
    };

    dfs2(dfs2, 1, 0);

    cout << ans << "\n";
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