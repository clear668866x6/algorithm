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

    vector<vector<vector<vector<i64>>>> f(
        n + 1, vector<vector<vector<i64>>>(3, vector<vector<i64>>(2, vector<i64>(1024, -1))));

    auto dfs = [&](auto &&dfs, int u, int tot, int is3, int mask, bool lead, bool lim) -> int {
        if (u == -1) {
            int t1 = tot % 3 == 0;
            int t2 = is3;
            int t3 = __builtin_popcount(mask) == 3;

            int t = (t1 + t2 + t3);

            return !lead && t == 1;
        }

        if (!lim && !lead && f[u][tot][is3][mask] != -1) return f[u][tot][is3][mask];

        i64 ans = 0;
        int up = lim ? num[u] : 9;
        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                ans += dfs(dfs, u - 1, (tot * 10 + i) % 3, is3, mask, true, lim && (i == up));
            } else {
                ans += dfs(dfs, u - 1, (tot * 10 + i) % 3, is3 | (i == 3), mask | (1 << i), false, lim && (i == up));
            }
            ans %= mod;
        }

        if (!lim && !lead) f[u][tot][is3][mask] = ans;

        return ans;
    };

    cout << dfs(dfs, n - 1, 0, 0, 0, true, true);
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