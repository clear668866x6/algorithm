#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> w(1 << (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = (1 << (n - i)); j < (1 << (n - i + 1)); j++) {
            cin >> w[j][1];
        }
    }

    cin >> w[1][0];

    auto dfs = [&](auto &&dfs, int u) -> int {
        if (u >= (1 << n)) return 1;
        if (w[u][0] < w[u][1]) return 0;

        w[u * 2][0] = w[u][0];
        w[u * 2 + 1][0] = w[u][1];
        if (dfs(dfs, u * 2) && dfs(dfs, u * 2 + 1)) return 1;

        w[u * 2][0] = w[u][1];
        w[u * 2 + 1][0] = w[u][0];
        if (dfs(dfs, u * 2) && dfs(dfs, u * 2 + 1)) return 1;
        return 0;
    };

    if (dfs(dfs, 1)) {
        for (int i = (1 << (n - 1)); i < (1 << n); i++) {
            cout << w[i][0] << ' ' << w[i][1] << " \n"[i == (1 << n) - 1];
        }
    } else {
        cout << "No Solution";
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