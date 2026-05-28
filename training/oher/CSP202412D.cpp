#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), k(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> k[i];

    vector<int> d(n + 1, 1e9);
    d[1] = 0;

    struct E {
        int x, y;
        bool operator<(const E &t) const {
            if (x != t.x) return x > t.x;
            return y < t.y;
        }
    };

    priority_queue<E> q;
    q.push({0, 1});
    vector<int> vis(n + 1, 0);
    set<int> s;
    for (int i = 2; i <= n; i++) s.insert(i);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (ver == n) {
            cout << d[ver];
            return;
        }

        if (vis[ver]) continue;
        vis[ver] = 1;

        auto l = s.upper_bound(ver);

        for (auto it = l; *it <= min(n, ver + k[ver]) && it != s.end();) {
            int j = *it;
            if (d[j - a[j]] > d[ver] + 1) {
                d[j - a[j]] = d[ver] + 1;
                q.push({d[j - a[j]], j - a[j]});
            }
            it = s.erase(it);
        }
    }

    if (d[n] == 1e9) d[n] = -1;

    cout << d[n];
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