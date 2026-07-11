#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x < 0) cnt++;
    }

    if (cnt == n) {
        cout << "Yes";
    } else {
        cout << "No";
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