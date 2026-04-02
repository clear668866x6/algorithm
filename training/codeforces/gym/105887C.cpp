#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> w(n + 2, vector<int>(n + 2, 0));

    int t = 1;
    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = j;
        }
        for (int j = 1; j <= n; j++) {
            w[i + 1][j] = (j + t - 1) % n + 1;
        }
        t++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << w[i][j] << ' ';
        }
        cout << "\n";
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