#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> w(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int y;
            cin >> y;
            w[i].push_back(y);
        }
    }

    int x, y;
    cin >> x >> y;
    cout << w[x][y - 1];
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