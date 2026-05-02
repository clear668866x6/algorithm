#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n = 6;
    vector<vector<int>> w(4, vector<int>(n + 1, 0));

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    int tot = 6 * 6 * 6;
    int t = 0;

    vector<int> p{4, 5, 6};

    do {
        int tp = 1;
        for (int i = 0; i < 3; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (w[i + 1][j] == p[i]) cnt++;
            }
            tp *= cnt;
        }
        t += tp;
    } while (next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(12) << ((double)t / tot);
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