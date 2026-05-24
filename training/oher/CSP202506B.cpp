#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;

    array<int, 8> dx = {1, 2, 2, 1, -1, -2, -2, -1};
    array<int, 8> dy = {2, 1, -1, -2, -2, -1, 1, 2};

    int x, y;
    cin >> x >> y;
    vector vis(n + 1, vector(n + 1, 0));

    queue<array<int, 3>> q;
    q.push({0, x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto [step, x, y] = q.front();
        q.pop();

        if (step == k) continue;

        for (int i = 0; i < 8; i++) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > n || vis[a][b]) continue;
            vis[a][b] = 1;
            q.push({step + 1, a, b});
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += vis[i][j];
        }
    }

    cout << cnt;
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