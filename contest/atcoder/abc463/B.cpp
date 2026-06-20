#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    vector<vector<char>> a(n + 1, vector<char>(5 + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }

    int t = c - 'A' + 1;

    for (int i = 1; i <= n; i++) {
        if (a[i][t] == 'o') {
            cout << "Yes";
            return;
        }
    }

    cout << "No";
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