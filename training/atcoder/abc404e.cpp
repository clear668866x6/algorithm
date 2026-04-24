#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> c(n), a(n);
    for (int i = 1; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        for (int j = i - c[i]; j <= i - 1; j++) {
            g[j].push_back(i);
        }
    }

    int tot = accumulate(a.begin(), a.end(), 0ll);
    map<int, int> mp;

    vector<int> vis(n, 0);
    vector<int> nxt(n + 1, -1);
    int lst = -1;

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = lst;
        if (a[i] == 1) {
            lst = i;
        }
    }

    vector<int> f(n + 1, -1);
    int mx = 0;

    auto dfs = [&](auto &&dfs, int u) -> int {
        if (nxt[u] == -1) return 0;
        if (f[u] != -1) return f[u];
        int mn = 1e9;
        int t = nxt[u];

        for (auto v : g[u]) {
            if (v > t) continue;
            mn = min(mn, dfs(dfs, v) + 1);
        }
        return f[u] = mn;
    };

    cout << dfs(dfs, 0);
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