#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int b, c, l, r;
    cin >> b >> c >> l >> r;

    i64 ans = 0;

    auto f = [&](i64 x) { return x * x + b * x + c; };

    for (int i = l; i <= r; i++) {
        if (!(i & 1)) {
            ans += f(i);
        }
    }

    cout << 2 * ans;
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