#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int l, n;
    cin >> l >> n;

    vector cur(n + 1, vector(n + 1, 0));

    int ans = 0;
    vector col(n + 1, 0);

    auto dfs = [&](auto &&dfs, int x, int y, int tot) {
        if (col[y] > l) return;
        if (x == n && y == n + 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    int c1 = 0, c2 = 0;
                    for (int x = 1; x <= n; x++) {
                        c1 += cur[i][x];
                        c2 += cur[x][j];
                    }
                    if (c1 != l || c2 != l) {
                        return;
                    }
                }
            }
            ans++;
            return;
        }

        if (x == n) {
            if (l - col[y] >= 0) {
                int t = col[y];
                cur[x][y] = l - col[y];
                col[y] += (l - t);
                dfs(dfs, x, y + 1, tot + cur[x][y]);
                col[y] -= (l - t);
            } else {
                return;
            }
        } else if (y == n) {
            if (l - tot >= 0) {
                cur[x][y] = l - tot;
                col[y] += (l - tot);
                dfs(dfs, x + 1, 1, 0);
                col[y] -= (l - tot);
            } else {
                return;
            }
        } else {
            for (int i = 0; i <= l - tot; i++) {
                cur[x][y] = i;
                col[y] += i;
                dfs(dfs, x, y + 1, tot + i);
                col[y] -= i;
            }
        }
    };

    dfs(dfs, 1, 1, 0);

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