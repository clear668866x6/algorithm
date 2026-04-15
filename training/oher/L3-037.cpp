#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    vector w(n + 1, vector(m + 1, 0));

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    int edx = 0, edy = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            if (w[i][j] == 2) edx = i, edy = j;
        }
    }

    int q;
    cin >> q;
    map<array<int, 2>, int> mp;
    map<int, int> mp2;
    vector d(n + 1, vector(m + 1, (int)1e9));
    vector vis(n + 1, vector(m + 1, 0));
    vector x(q + 1, 0), y(q + 1, 0);

    for (int idx = 1; idx <= q; idx++) {
        cin >> y[idx] >> x[idx];
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> qq;
    qq.push({0, edx, edy});
    d[edx][edy] = 0;

    while (!qq.empty()) {
        auto [dd, x, y] = qq.top();
        qq.pop();

        if (vis[x][y]) continue;
        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m || w[a][b] == 0) continue;
            if (d[a][b] > d[x][y] + 1) {
                d[a][b] = d[x][y] + 1;
                qq.push({d[a][b], a, b});
            }
        }
    }

    for (int idx = 1; idx <= q; idx++) {
        mp[{d[x[idx]][y[idx]], idx}]++;
        mp2[d[x[idx]][y[idx]]]++;
    }

    for (auto [x, y] : mp) {
        auto [d, idx] = x;
        if (d != 1e9) {
            if (mp2[d] == 1) {
                cout << idx << ' ' << d;
                return;
            }
        }
    }

    cout << "No winner.";
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