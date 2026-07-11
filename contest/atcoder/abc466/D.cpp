#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1, 0), b(m + 1, 0);

    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];

    vector<int> r(n + 1, 0), c(n + 1, 0);

    int ans = 0;

    for (int i = m; i >= 1; i--) {
        int x = a[i], y = b[i];
        if (!(r[x] || c[y])) {
            ans++;
        }
        r[x] = c[y] = 1;
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