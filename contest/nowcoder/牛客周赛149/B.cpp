#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    if (n & 1) {
        cout << -1;
    } else {
        for (int i = 1; i <= n / 2; i++) cout << 1;
        for (int i = 1; i <= n / 2; i++) cout << 0;
    }
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