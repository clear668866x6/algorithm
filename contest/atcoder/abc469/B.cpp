#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'x' && ((i - 1 >= 1 && s[i - 1] == 'x') || i - 1 == 0) &&
            ((i + 1 <= n && s[i + 1] == 'x') || i + 1 == n + 1))
            ans++;
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