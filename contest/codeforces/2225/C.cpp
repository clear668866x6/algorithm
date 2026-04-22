#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = ' ' + s1, s2 = ' ' + s2;

    vector<int> f(n + 2, 0);

    for (int i = 2; i <= n + 1; i++) {
        if (s1[i - 1] != s2[i - 1]) {
            f[i] = 1;
        }
        if (i > 2) {
            f[i] = min(f[i - 2] + (s1[i - 1] != s1[i - 2]) + (s2[i - 1] != s2[i - 2]),
                       f[i - 1] + (s1[i - 1] != s2[i - 1]));
        }
    }

    cout << f[n + 1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}