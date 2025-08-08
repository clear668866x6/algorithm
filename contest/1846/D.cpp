#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n, d, h;
    cin >> n >> d >> h;

    V<int> y(n + 1, 0);

    FOR(i, 1, n) cin >> y[i];

    double ans = 1. * d * h / 2.0 * n;

    double area = 1. * d * h / 2.0, cnt = 0;
    FOR(i, 2, n) {
        if (y[i] - y[i - 1] < h) {
            int del = y[i] - y[i - 1];
            double p = pow((1. * (h - del)) / (1.0 * h), 2);
            ans -= area * p;
        }
    }

    cout << setprecision(12) << fixed << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
