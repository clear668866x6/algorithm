#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<array<i64, 2>> w(n + 1);

    multiset<int> s;
    map<int, i64> mp;

    for (int i = 1; i <= n; i++) {
        cin >> w[i][0] >> w[i][1], s.insert(w[i][1]);
        mp[w[i][0]] = max(mp[w[i][0]], w[i][1]);
    }

    i64 ans = 0;

    vector<i64> c;

    for (auto [x, y] : mp) {
        c.push_back(y);
    }

    sort(c.rbegin(), c.rend());

    for (int i = 0; i < m; i++) {
        ans += c[i];
        s.erase(s.find(c[i]));
    }

    k -= m;

    while (k--) {
        ans += *s.rbegin();
        s.erase(s.find(*s.rbegin()));
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