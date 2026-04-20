#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int delx = abs(x1 - x2);
    int dely = abs(y1 - y2);

    int ans = max((delx + 1) / 2, (dely + 1) / 2);

    if (x1 == x2 || y1 == y2) {
        if (ans & 1) ans++;
    }
    cout << ans << "\n";
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