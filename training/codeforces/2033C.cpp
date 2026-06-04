#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int l = (n + 1) / 2, r = (n + 1) / 2;

    if (!(n & 1)) {
        r++;
    }

    while (l - 1 >= 1 && r + 1 <= n) {
        if (a[l] == a[l - 1] || a[r] == a[r + 1]) {
            swap(a[r + 1], a[l - 1]);
        }
        l--, r++;
    }

    int ans = 0;

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            ans++;
        }
    }
    cout << ans << "\n";
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