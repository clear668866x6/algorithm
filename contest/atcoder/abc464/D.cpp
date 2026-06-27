#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<i64> x(n + 1, 0), y(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n - 1; i++) cin >> y[i];

    vector<vector<i64>> f(n + 1, vector<i64>(2, -1e9));

    f[1][0] = -(s[1] != 'R') * x[1], f[1][1] = -(s[1] != 'S') * x[1];

    for (int i = 2; i <= n; i++) {
        f[i][0] = max(f[i - 1][0] - (s[i] != 'R') * x[i], f[i - 1][1] - (s[i] != 'R') * x[i]);
        f[i][1] = max(f[i - 1][0] + y[i - 1] - x[i] * (s[i] != 'S'), f[i - 1][1] - (s[i] != 'S') * x[i]);
    }

    cout << max(f[n][0], f[n][1]) << '\n';
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