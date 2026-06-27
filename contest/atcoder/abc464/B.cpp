#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> s(n + 1, vector<char>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
        }
    }

    int l1 = 1e9, r1 = 0, l2 = 1e9, r2 = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                l1 = min(l1, j);
                r1 = max(r1, j);
                l2 = min(l2, i);
                r2 = max(r2, i);
            }
        }
    }

    for (int i = l2; i <= r2; i++) {
        for (int j = l1; j <= r1; j++) {
            cout << s[i][j];
        }
        cout << '\n';
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