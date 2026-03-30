#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(m + 1, 0), a(n + 1, 0);
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto f = [&](int x, int k) { return ((x * x + k * k) % 8) ^ k; };

    auto change = [&](int x, int k) {
        int t1 = (x >> 6) % 8, t2 = (x >> 3) % 8, t3 = x % 8;
        int b = t1;
        int c = t2 ^ f(t1, k);
        int a = t3 ^ f(c, k);
        int nx = (a << 6) + (b << 3) + c;
        return nx;
    };

    vector<int> ans(1 << 10, 0);

    for (int i = 0; i < (1 << 9); i++) {
        int x = i;
        for (int j = m; j >= 1; j--) {
            x = change(x, b[j]);
        }

        ans[i] = x;
    }

    for (int i = 1; i <= n; i++) cout << ans[a[i]] << ' ';
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