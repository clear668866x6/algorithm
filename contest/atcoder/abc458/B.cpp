#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ans = 0;
            for (int k = 0; k < 4; k++) {
                int a = dx[k] + i, b = dy[k] + j;
                if (a < 1 || b < 1 || a > n || b > m) continue;
                ans++;
            }
            cout << ans << ' ';
        }
        cout << "\n";
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