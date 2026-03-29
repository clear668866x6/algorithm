#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<i64> f(n + 1, 1e18), s(n + 1, 0);
    vector<vector<i64>> sm(n + 1, vector<i64>(n + 1, 1e18));

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] ^ w[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) {
                sm[i][j] = s[i];
            } else {
                sm[i][j] = min(sm[i][j - 1], s[i] ^ s[j]);
            }
        }
    }

    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            f[i] = min(f[i], f[j] + sm[i][j]);
        }
    }

    cout << f[n] << "\n";
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