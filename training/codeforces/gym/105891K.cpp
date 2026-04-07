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
        if (n > 0) {
            if (m > 0) {
                if (x > y * (n + 1)) {
                    cout << x + n * y << '\n';
                } else {
                    cout << max(x + n * y, x + (n - (x - 1) / y + m) * y) << '\n';
                }
            } else {
                cout << max(n * y, x + (n - 1) * y) << '\n';
            }
        } else {
            if (x > y) {
                if (m > 0) {
                    cout << x << '\n';
                } else {
                    cout << "0\n";
                }
            } else {
                cout << y * m << '\n';
            }
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