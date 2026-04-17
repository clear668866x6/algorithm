#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    while (n--) {
        vector<int> w(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            cin >> w[i];
        }

        vector<vector<int>> g(m + 1);

        for (int i = 1; i <= m; i++) {
            if (i / 2 >= 1) {
                g[i / 2].push_back(i);
            }
        }

        bool ismx = false, ismn = false;

        for (int i = 1; i <= m; i++) {
            for (auto v : g[i]) {
                if (w[i] > w[v]) {
                    ismx = 1;
                } else {
                    ismn = 1;
                }
            }
        }

        vector<int> ans;
        auto dfs = [&](auto &&dfs, int u) -> void {
            for (auto v : g[u]) {
                dfs(dfs, v);
            }
            ans.push_back(u);
        };

        if (ismx && ismn) {
            cout << "Not Heap\n";
        } else if (ismx) {
            cout << "Max Heap\n";
        } else if (ismn) {
            cout << "Min Heap\n";
        }

        dfs(dfs, 1);

        for (int i = 0; i < ans.size(); i++) cout << w[ans[i]] << " \n"[i == (int)ans.size() - 1];
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