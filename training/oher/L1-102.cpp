#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<double> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    int x, y;
    double ans = 0;
    vector<int> p(n + 1, 0);
    while (cin >> x >> y) {
        if (!x) break;
        ans += (y * w[x]);
        p[x] += y;
    }

    for (int i = 1; i <= n; i++) cout << p[i] << "\n";
    cout << fixed << setprecision(2) << ans;
}

int main() {
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}