#include <bits/stdc++.h>
using namespace std;

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<array<int, 3>>> g(n + 1), g2(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g2[b].push_back({a, c, d});
    }

    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto dij = [&](int x, vector<int> &d, int op) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
        d[x] = 0;
        vector vis(n + 1, 0);
        q.push({d[x], x});
        while (!q.empty()) {
            auto [dd, ver] = q.top();
            q.pop();

            if (vis[ver]) continue;
            vis[ver] = 1;

            if (op == 0) {
                for (auto [v, c1, c2] : g[ver]) {
                    if (d[v] > d[ver] + c1) {
                        d[v] = d[ver] + c1;
                        q.push({d[v], v});
                    }
                }
            } else {
                for (auto [v, c1, c2] : g2[ver]) {
                    if (d[v] > d[ver] + c2) {
                        d[v] = d[ver] + c2;
                        q.push({d[v], v});
                    }
                }
            }
        }
    };

    vector<int> d1(n + 1, 1e18), d2(n + 1, 1e18);

    dij(1, d1, 0);
    dij(n, d2, 1);

    vector<int> d(n + 1, 0);
    multiset<int> s;

    for (int i = 1; i <= n; i++) {
        int p1 = d2[i], p2 = d1[i];
        if (p1 != 1e18 && p2 != 1e18) {
            int k = (p1 + a[i] - 1) / a[i] + p2;
            s.insert(k);
            d[i] = k;
        }
    }

    while (q--) {
        int x, c;
        cin >> x >> c;
        a[x] = c;
        int p1 = d2[x], p2 = d1[x];
        if (p1 != 1e18 && p2 != 1e18) {
            int k = (p1 + a[x] - 1) / a[x] + p2;
            s.erase(s.find(d[x]));
            s.insert(k);
            d[x] = k;
        }
        if (!s.empty()) {
            cout << *s.begin() << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}