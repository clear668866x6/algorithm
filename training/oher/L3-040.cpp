#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int b, n, m, q;
    cin >> b >> n >> m >> q;

    vector<vector<array<int, 3>>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }

    struct E {
        i64 a, b, c;
        bool operator<(const E &t) const {
            if (a == t.a) return b < t.b;
            return a > t.a;
        }
    };

    while (q--) {
        int x;
        cin >> x;
        vector<i64> d0(n + 1, 1e18), d1(n + 1, 0);
        auto diji = [&](int st) {
            priority_queue<E> q;
            d0[st] = d1[st] = 0;
            q.push({0, 0, st});
            vector<int> vis(n + 1, 0);

            while (!q.empty()) {
                auto [dd, cc, ver] = q.top();
                q.pop();

                if (vis[ver]) continue;
                vis[ver] = 1;

                for (auto [v, w1, w2] : g[ver]) {
                    if (d0[v] > d0[ver] + w1) {
                        d0[v] = d0[ver] + w1;
                        d1[v] = d1[ver] + w2;
                        q.push({d0[v], d1[v], v});
                    } else if (d0[v] == d0[ver] + w1) {
                        if (d1[v] < d1[ver] + w2) {
                            d1[v] = d1[ver] + w2;
                            q.push({d0[v], d1[v], v});
                        }
                    }
                }
            }
        };
        diji(x);

        vector<int> ans1, ans2;
        i64 mx = 0;

        for (int j = 1; j <= n; j++) {
            if (d0[j] <= b && j != x) {
                ans1.push_back(j);
                mx = max(mx, d1[j]);
            }
        }

        for (auto x : ans1) {
            if (mx == d1[x]) {
                ans2.push_back(x);
            }
        }

        if (ans1.empty()) {
            cout << "T_T\n";
        } else {
            int n1 = ans1.size(), n2 = ans2.size();
            for (int i = 0; i < n1; i++) cout << ans1[i] << " \n"[i == n1 - 1];
            for (int i = 0; i < n2; i++) cout << ans2[i] << " \n"[i == n2 - 1];
        }
    }
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