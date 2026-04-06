#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct P {
    int f, t;
    double x, y;

    bool operator<(const P &t) const {
        return atan2(y, x) < atan2(t.y, t.x);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<P> w(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i].x >> w[i].y;
    }

    vector<P> p;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            p.push_back({i, j, w[i].x - w[j].x, w[i].y - w[j].y});
        }
    }

    sort(p.begin(), p.end());

    vector<int> f(n + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) f[j] = -1e9;
        f[i] = 0;
        for (int j = 0; j < p.size(); j++) {
            f[p[j].t] = max(f[p[j].t], f[p[j].f] + 1);
        }
        ans = max(ans, f[i]);
    }

    cout << ans;
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