#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    vector<int> p(25, y);

    for (int i = l; i <= r - 1; i++) p[i] = x;

    int ans = 0;

    for (int i = a; i <= b - 1; i++) ans += p[i];

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