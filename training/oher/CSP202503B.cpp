#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1, 0);
    for (int i = 1; i <= m; i++) cin >> a[i];

    vector<int> f(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = max(f[j], f[j - i] + a[i]);
        }
    }

    cout << f[n];
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