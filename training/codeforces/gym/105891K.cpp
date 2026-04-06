#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    i64 n, m, x, y;
    cin >> n >> m >> x >> y;

    if (x <= y) {
        cout << (n + m) * y << '\n';
    } else {
        if (!y) {
            cout << max(n * y, (n - 1) * y + x) << '\n';
            return;
        }
        int t = n / y;
        if (t <= n) {
            cout << x + (n - t + m) * y << '\n';
        } else {
            cout << max(x + (n - 1) * y, (n + m) * y) << '\n';
        }
    }
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