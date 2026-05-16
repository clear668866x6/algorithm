#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'C') {
            int t = min(i, n - i + 1);
            ans += t;
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