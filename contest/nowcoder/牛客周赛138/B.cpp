#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x, y;
    cin >> x >> y;

    int ans = 0;

    for (int i = 0; i <= 32; i++) {
        ans = max(ans, (x >> i) ^ y);
        ans = max(ans, x ^ (y >> i));
    }

    cout << ans << '\n';
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