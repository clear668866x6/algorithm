#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<vector<int>> w(n + 1);
    vector<i64> len(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        len[i] = t;
        w[i].resize(t + 1, 0);
        for (int j = 1; j <= t; j++) {
            cin >> w[i][j];
        }
    }

    vector<i64> c(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> c[i];

    i64 tot = 0;

    for (int i = 1; i <= n; i++) {
        if (tot + len[i] * c[i] < k) {
            tot += len[i] * c[i];
        } else {
            i64 del = k - tot;
            del = (del - 1) % len[i] + 1;

            cout << w[i][del];
            break;
        }
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