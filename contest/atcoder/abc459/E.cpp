#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    vector<i64> c(n + 1, 0), d(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    vector<i64> siz(n + 1, 0);
    i64 ans = 1;

    auto qmi = [&](i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    auto C = [&](i64 x, i64 y) {
        if (x < 0 || y < 0 || x - y < 0) return 0ll;
        i64 ans = 1;
        i64 fm = 1;
        x %= mod;
        for (int i = 1, j = 1; i <= y; i++, j++) {
            ans = ans * x % mod;
            fm *= j;
            fm %= mod;
            ans %= mod;
            x--;
        }
        ans *= qmi(fm, mod - 2);
        ans %= mod;
        return ans;
    };

    auto dfs = [&](this auto &dfs, int u, int fa) {
        if (g[u].size() == 1 && u != 1) {
            siz[u] = c[u] - d[u];
            ans *= C(c[u], d[u]);
            ans %= mod;
            return;
        }
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
        siz[u] += c[u];
        ans *= C(siz[u], d[u]);
        ans %= mod;
        siz[u] -= d[u];
    };

    dfs(1, 0);

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