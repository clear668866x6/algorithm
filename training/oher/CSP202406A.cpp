#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector<int> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
    }

    int idx = 0;

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            cout << c[idx++] << ' ';
        }
        cout << '\n';
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