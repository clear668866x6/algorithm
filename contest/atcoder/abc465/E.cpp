#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

void solve() {
    string s;
    cin >> s;

    vector<int> num;
    for (auto x : s) {
        num.push_back(x - '0');
    }
    reverse(num.begin(), num.end());
    int n = num.size();

    vector<vector<i64>> f(n + 1, vector<i64>(4, -1));
    vector<vector<i64>> f2(n + 1, vector<i64>(2, -1));
    vector<vector<i64>> f3(n + 1, vector<i64>(1024, -1));
    vector<vector<vector<i64>>> f4(n + 1, vector<vector<i64>>(4, vector<i64>(4, -1)));
    vector<vector<vector<i64>>> f5(n + 1, vector<vector<i64>>(4, vector<i64>(1024, -1)));
    vector<vector<vector<i64>>> f6(n + 1, vector<vector<i64>>(4, vector<i64>(1024, -1)));
    vector<vector<vector<vector<i64>>>> f7(
        n + 1, vector<vector<vector<i64>>>(4, vector<vector<i64>>(4, vector<i64>(1024, -1))));

    auto dfs1 = [&](auto &&dfs1, int u, int tot, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && tot % 3 == 0;
        }

        if (!lim && !lead && f[u][tot] != -1) return f[u][tot];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs1(dfs1, u - 1, (tot * 10 + i) % 3, true, lim && (i == up));
            } else {
                ans += dfs1(dfs1, u - 1, (tot * 10 + i) % 3, false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f[u][tot] = ans;
        }

        return ans;
    };

    auto dfs2 = [&](auto &&dfs2, int u, bool is3, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && is3;
        }

        if (!lim && !lead && f2[u][is3] != -1) return f2[u][is3];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs2(dfs2, u - 1, is3 | (i == 3), true, lim && (i == up));
            } else {
                ans += dfs2(dfs2, u - 1, is3 | (i == 3), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f2[u][is3] = ans;
        }

        return ans;
    };

    auto dfs3 = [&](auto &&dfs3, int u, int mask, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && __builtin_popcount(mask) == 3;
        }

        if (!lim && !lead && f3[u][mask] != -1) return f3[u][mask];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs3(dfs3, u - 1, mask, true, lim && (i == up));
            } else {
                ans += dfs3(dfs3, u - 1, mask | (1 << i), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f3[u][mask] = ans;
        }

        return ans;
    };

    auto dfs4 = [&](auto &&dfs4, int u, int tot, int is3, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && tot % 3 == 0 && is3;
        }

        if (!lim && !lead && f4[u][tot][is3] != -1) return f4[u][tot][is3];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs4(dfs4, u - 1, (tot * 10 + i) % 3, is3 | (i == 3), true, lim && (i == up));
            } else {
                ans += dfs4(dfs4, u - 1, (tot * 10 + i) % 3, is3 | (i == 3), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f4[u][tot][is3] = ans;
        }

        return ans;
    };

    auto dfs5 = [&](auto &&dfs5, int u, int tot, int mask, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && tot % 3 == 0 && __builtin_popcount(mask) == 3;
        }

        if (!lim && !lead && f5[u][tot][mask] != -1) return f5[u][tot][mask];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs5(dfs5, u - 1, (tot * 10 + i) % 3, mask, true, lim && (i == up));
            } else {
                ans += dfs5(dfs5, u - 1, (tot * 10 + i) % 3, mask | (1 << i), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f5[u][tot][mask] = ans;
        }

        return ans;
    };

    auto dfs6 = [&](auto &&dfs6, int u, bool is3, int mask, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && is3 && __builtin_popcount(mask) == 3;
        }

        if (!lim && !lead && f6[u][is3][mask] != -1) return f6[u][is3][mask];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs6(dfs6, u - 1, is3 | (i == 3), mask, true, lim && (i == up));
            } else {
                ans += dfs6(dfs6, u - 1, is3 | (i == 3), mask | (1 << i), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f6[u][is3][mask] = ans;
        }

        return ans;
    };

    auto dfs7 = [&](auto &&dfs7, int u, int tot, bool is3, int mask, bool lead, bool lim) -> int {
        if (u == -1) {
            return !lead && is3 && __builtin_popcount(mask) == 3 && tot == 0;
        }

        if (!lim && !lead && f7[u][tot][is3][mask] != -1) return f7[u][tot][is3][mask];

        i64 ans = 0;

        int up = lim ? num[u] : 9;

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs7(dfs7, u - 1, (tot * 10 + i) % 3, is3 | (i == 3), mask, true, lim && (i == up));
            } else {
                ans += dfs7(dfs7, u - 1, (tot * 10 + i) % 3, is3 | (i == 3), mask | (1 << i), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) {
            f7[u][tot][is3][mask] = ans;
        }

        return ans;
    };

    i64 ans1 = dfs1(dfs1, n - 1, 0, true, true);
    i64 ans2 = dfs2(dfs2, n - 1, 0, true, true);
    i64 ans3 = dfs3(dfs3, n - 1, 0, true, true);
    i64 ans4 = dfs4(dfs4, n - 1, 0, 0, true, true);
    i64 ans5 = dfs5(dfs5, n - 1, 0, 0, true, true);
    i64 ans6 = dfs6(dfs6, n - 1, 0, 0, true, true);
    i64 ans7 = dfs7(dfs7, n - 1, 0, 0, 0, true, true);

    i64 ans = (ans1 + mod) % mod;
    ans = (ans + ans2) % mod;
    ans = (ans + ans3) % mod;
    ans = (ans - 2 * ans4 % mod + mod) % mod;
    ans = (ans - 2 * ans5 % mod + mod) % mod;
    ans = (ans - 2 * ans6 % mod + mod) % mod;
    ans = (ans + 3 * ans7 % mod + mod) % mod;
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