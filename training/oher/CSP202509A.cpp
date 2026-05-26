#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, a;
    cin >> n >> a;

    auto get = [&](double x1, double y1) { return x1 * x1 + y1 * y1; };

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        if (get(x, y) <= a * a) {
            cnt++;
        }
    }

    double ans = 4.0 * cnt / n;

    cout << fixed << setprecision(8) << ans;
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