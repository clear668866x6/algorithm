#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct Comb {
    static constexpr int N = 2e3;
    i64 fac[N], infac[N];

    i64 qmi(i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

    void init() {
        fac[0] = 1;
        int n = N - 10;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) infac[i] = infac[i + 1] * (i + 1) % mod;
    }

    i64 A(i64 x, i64 y) {
        return fac[x] * infac[x - y] % mod;
    }

} A;

void solve() {
    int n;
    i64 x;
    cin >> n >> x;

    vector<i64> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    A.init();

    i64 ans = 0;
    map<array<i64, 2>, i64> mp;
    auto qmi = [&](i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    auto dfs = [&](auto &&dfs, int u, i64 val, int cnt) {
        if (val > x) {
            i64 p = A.A(cnt, cnt);
            ans = (ans + val * qmi(p, mod - 2) % mod * p % mod) % mod;
            return;
        }
        if (u >= (n + 1) / 2 + 1) {
            mp[{cnt, val}]++;
            return;
        }

        dfs(dfs, u + 1, val + a[u], cnt + 1);
        dfs(dfs, u + 1, val, cnt);
    };

    dfs(dfs, 1, 0, 0);

    vector<i64> p(1, 0), c(1, 0);
    for (auto [x, y] : mp) {
        p.push_back(x[0]);
        c.push_back(x[1]);
    }

    auto get = [&](i64 x) { return lower_bound(p.begin(), p.end(), x) - p.begin(); };

    int m = (int)p.size() - 1;
    vector<i64> s(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        s[i] = s[i - 1] + p[i];
        s[i] %= mod;
    }

    auto dfs2 = [&](auto &&dfs2, int u, i64 val, int cnt) {
        if (val > x) {
            i64 p = A.A(cnt, cnt);
            ans = (ans + val * qmi(p, mod - 2) % mod * p % mod) % mod;
            return;
        }
        if (u >= n + 1) {
            i64 rm = x - val;
            int cnt2 = cnt + return;
        }

        dfs2(dfs2, u + 1, val + a[u], cnt + 1);
        dfs2(dfs2, u + 1, val, cnt);
    };

    dfs2(dfs2, 1, 0, 0);

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