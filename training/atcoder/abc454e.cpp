#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (n & 1 || !((a + b) & 1)) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    auto dfs = [&](auto &&dfs, int n, int m, int x, int y) {
        if (n == 2 && m == 2) {
            if (x == 1) {
                cout << "DR";
            } else {
                cout << "RD";
            }
            return;
        }

        if (x > 2) {
            for (int i = 1; i < m; i++) cout << "R";
            cout << "D";
            for (int i = 1; i < m; i++) cout << "L";
            cout << "D";
            dfs(dfs, n - 2, m, x - 2, y);
        } else if (y > 2) {
            for (int i = 1; i < n; i++) cout << "D";
            cout << "R";
            for (int i = 1; i < n; i++) cout << "U";
            cout << "R";
            dfs(dfs, n, m - 2, x, y - 2);
        } else if (x < n - 1) {
            dfs(dfs, n - 2, m, x, y);
            cout << "D";
            for (int i = 1; i < m; i++) cout << "L";
            cout << "D";
            for (int i = 1; i < m; i++) cout << "R";
        } else if (y < m - 1) {
            dfs(dfs, n, m - 2, x, y);
            cout << "R";
            for (int i = 1; i < n; i++) cout << "U";
            cout << "R";
            for (int i = 1; i < n; i++) cout << "D";
        }
    };

    dfs(dfs, n, n, a, b);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}