#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    i64 n, l, r;
    cin >> n >> l >> r;

    vector<i64> ans;

    auto dfs = [&](auto &&dfs, i64 u, i64 cur) {
        if (u > n) {
            if (cur >= l && cur <= r) {
                ans.push_back(cur);
            }
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (u == 1 && i == 0) {
                continue;
            }
            if ((cur * 10 + i) % u == 0) {
                dfs(dfs, u + 1, cur * 10 + i);
            }
        }
    };

    dfs(dfs, 1, 0);

    if (ans.empty()) {
        cout << "No Solution";
    } else {
        for (auto x : ans) cout << x << '\n';
    }
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