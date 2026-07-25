#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> val(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'G') {
            for (int j = max(1, i - d); j <= min(n, i + d); j++) {
                val[j] = 1;
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '.' && !val[i]) {
            ans++;
        }
    }

    cout << ans;
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