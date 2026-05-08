#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == m && n != 1) {
        cout << "YES\n";
        vector<int> w(n + 1, 0);
        iota(w.begin(), w.end(), 0);
        cout << 2 << '\n';
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cout << w[j] << ' ';
            }
            for (int j = 1; j <= i - 1; j++) {
                cout << w[j] << ' ';
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
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