#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1, 0);
    for (int i = 0; i <= n; i++) cin >> a[i];

    cout << "0 " << a[0] << '\n';

    int t = a[0];

    for (int i = 1; i <= n; i++) {
        if (abs(t - a[i]) >= x) {
            cout << i << ' ' << a[i] << '\n';
            t = a[i];
        }
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