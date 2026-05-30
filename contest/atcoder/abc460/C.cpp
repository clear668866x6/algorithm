#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int ans = 0;

    multiset<int> s;
    for (int i = 1; i <= n; i++) s.insert(a[i]);

    sort(b.begin() + 1, b.end());

    for (int i = 1; i <= m; i++) {
        auto it = s.lower_bound((b[i] + 1) / 2);
        if (it != s.end()) {
            ans++;
            s.erase(s.find(*it));
        }
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