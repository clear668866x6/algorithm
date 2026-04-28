#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct P {
    int x, y, idx;
    long double ang;
    P() {}
    P(int _x, int _y, int _idx) : x(_x), y(_y), idx(_idx) {
        ang = atan2(y, x);
    }

    long double alpha() {
        return atan2l(y, x);
    }

    int det(P p) {
        return x * p.y - y * p.x;
    }
};

const long double pi = acosl(-1);

void solve() {
    int n;
    cin >> n;

    vector<int> x(n + 1, 0), y(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    vector<P> w;

    for (int i = 1; i <= n; i++) {
        P a(x[i], y[i], i);
        w.push_back(a);
    }

    sort(w.begin(), w.end(), [&](P a, P b) {
        long double pa = a.ang, pb = b.ang;
        if (pa != pb) return pa < pb;
        return a.det(b) > 0;
    });

    long double mn = 1e18L;
    int ans1 = 0, ans2 = 0;

    for (int i = 1; i < w.size(); i++) {
        if (min(2 * pi - (w[i].alpha() - w[i - 1].alpha()), w[i].alpha() - w[i - 1].alpha()) < mn) {
            mn = min(2 * pi - (w[i].alpha() - w[i - 1].alpha()), w[i].alpha() - w[i - 1].alpha());
            ans1 = w[i - 1].idx, ans2 = w[i].idx;
        }
    }

    if (min(2 * pi - (w.back().alpha() - w[0].alpha()), w.back().alpha() - w[0].alpha()) < mn) {
        mn = min(2 * pi - (w.back().alpha() - w[0].alpha()), w.back().alpha() - w[0].alpha());
        ans1 = w.back().idx, ans2 = w[0].idx;
    }

    cout << ans1 << ' ' << ans2;
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