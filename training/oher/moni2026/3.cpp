#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    cout << n << '\n';
    if (n < 0) {
        cout << "dan ren";
    } else if (n == 0) {
        cout << "xian ren";
    } else {
        cout << "nong ren";
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