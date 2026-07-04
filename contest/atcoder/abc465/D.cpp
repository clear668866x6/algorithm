#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;

    vector<i64> a, b;

    while (x) {
        a.push_back(x % k);
        x /= k;
    }

    while (y) {
        b.push_back(y % k);
        y /= k;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int ans = 0;

    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            cout << ((int)a.size() - i) + ((int)b.size() - i) << '\n';
            return;
        }
    }

    cout << abs((int)a.size() - (int)b.size()) << '\n';
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