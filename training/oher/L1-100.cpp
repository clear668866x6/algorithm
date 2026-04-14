#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    i64 tot = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        tot += x;
    }

    if (tot % n == 0) {
        cout << n;
    } else if (tot < n) {
        cout << 0;
    } else {
        cout << (tot - tot / n * n);
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