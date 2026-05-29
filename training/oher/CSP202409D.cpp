#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    vector<array<int, 4>> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3];

    auto chk = [&](array<int, 2> a, array<int, 4> b) {
        auto [x1, y1] = a;
        auto [x2, y2, r2, t2] = b;
        int lf = x2 - r2, rf = x2 + r2;
        int bt = y2 - r2, up = y2 + r2;
        if (x1 >= lf && x1 <= rf && y1 >= bt && y1 <= up) {
            return 1;
        }
        return 0;
    };

    vector<vector<int>> c(m + 1);

    sort(b.begin() + 1, b.end(), [&](auto a, auto b) { return a[3] < b[3]; });

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (chk(a[i], b[j])) {
                c[j].push_back(i);
            }
        }
    }

    vector<int> d(n + 1, 1e9);
    d[1] = 0;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({0, 1});

    vector<int> vis(n + 1, 0), vis2(m + 1, 0);

    while (!q.empty()) {
        auto [dd, ver] = q.top();
        q.pop();

        if (vis[ver]) continue;
        vis[ver] = 1;

        for (int j = 1; j <= m; j++) {
            if (vis2[j]) continue;
            if (chk(a[ver], b[j])) {
                vis2[j] = 1;
                for (auto x : c[j]) {
                    if (x == ver) continue;
                    if (d[x] > d[ver] + b[j][3]) {
                        d[x] = d[ver] + b[j][3];
                        q.push({d[x], x});
                    }
                }
            }
        }
    }

    if (d[n] == 1e9) {
        cout << "Nan";
    } else {
        cout << d[n];
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