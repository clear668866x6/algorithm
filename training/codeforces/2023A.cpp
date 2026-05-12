#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> w(n);

    for (auto &[z, x, y] : w) cin >> x >> y, z = x + y;

    ranges::sort(w);

    for (auto [z, x, y] : w) cout << x << ' ' << y << ' ';
    cout << "\n";
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