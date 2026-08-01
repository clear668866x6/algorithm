#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    vector<vector<int>> g(n + 1);
    map<array<int, 2>, int> mp;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        if (a > b) swap(a, b);
        mp[{a, b}]++;
        d[a]++, d[b]++;
    }

    vector<array<int, 2>> a;
    for (int i = 1; i <= n; i++) {
        a.push_back({d[i], i});
    }

    sort(a.begin(), a.end());

    int j = a.size();

    i64 ans = 0;

    for (int i = 0; i < a.size(); i++) {
        auto [dd, x] = a[i];
        j = max(j, i + 1);
        while (j - 1 > i && a[j - 1][0] + dd >= m) j--;
        if (j < n && j > i && a[j][0] + dd >= m) {
            ans += (n - j);
        }
    }

    for (auto [x, y] : mp) {
        auto [a, b] = x;
        if (d[a] + d[b] >= m && d[a] + d[b] - y < m) ans--;
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