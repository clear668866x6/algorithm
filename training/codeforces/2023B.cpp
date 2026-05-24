#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<i64> d(n + 1, 0);
    priority_queue<array<i64, 2>> q;
    q.push({0, 1});
    vector<int> vis(n + 1, 0);
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(i);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (ver == 0) continue;
        if (vis[ver]) continue;
        vis[ver] = 1;
        s.erase(s.find(ver));

        auto it = prev(s.upper_bound(b[ver]));
        int v = *it;
        d[v] = d[ver];
        q.push({d[v], v});

        it = prev(s.lower_bound(ver));
        v = *it;
        if (d[v] < d[ver] + a[ver]) {
            d[v] = d[ver] + a[ver];
            q.push({d[v], v});
        }
    }

    cout << max(d[0], a[1]) << '\n';
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