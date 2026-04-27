#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    int l = 2 * m, r = (i64)m * (m + 1) / 2 + 1;

    if (n >= l && n <= r) {
        cout << "YES\n";

        int del = n - 2 * m;

        int mx = m - 2;
        vector<int> vis(m + 1, 0);

        while (del) {
            if (del >= mx) {
                del -= mx;
                vis[mx] = 1;
                mx--;
            } else {
                int p = del;
                vis[p] = 1;
                del = 0;
            }
        }

        int idx = 1;
        for (int i = 1; i < m; i++, idx++) {
            cout << idx << ' ' << idx + 1 << '\n';
        }
        idx++;

        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                cout << i + 1 << ' ' << idx++ << '\n';
            }
        }

        for (int i = 0; i < m; i++) {
            if (vis[i]) {
                cout << "1 " << idx << '\n';
                for (int j = 1; j <= i; j++) {
                    cout << idx << " " << idx + 1 << "\n";
                    idx++;
                }
                idx++;
            }
        }

    } else {
        cout << "NO\n";
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