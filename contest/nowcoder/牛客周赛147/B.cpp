#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    i64 t = n / 5;
    i64 ans = 0;

    if (t & 1) {
        ans = 7 * (t / 2) + 4;
    } else {
        ans = 7 * (t / 2);
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