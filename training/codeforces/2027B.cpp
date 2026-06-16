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

    if (n == 1) {
        cout << "0\n";
        return;
    }

    int ans = n;

    for (int l = 1; l <= n; l++) {
        int tot = 0;
        for (int r = l + 1; r <= n; r++) {
            if (a[r] > a[l]) {
                tot++;
            }
            ans = min(ans, l - 1 + tot + (n - r));
        }
    }
    cout << ans << '\n';
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