#include <algorithm>
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
    int n;
    double s, t;
    cin >> n >> s >> t;

    V<array<int, 4>> w(n);

    for (auto& [a, b, c, d] : w)
        cin >> a >> b >> c >> d;

    function<double(int, int, int, int)> calc = [&](int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    };

    V<int> p(n + 1, 0);
    iota(p.begin() + 1, p.end(), 0LL);
    double ans = 1e18;

    do {
        double res = 0;
        FOR(i, 0, n - 1) res += calc(w[i][0], w[i][1], w[i][2], w[i][3]) / t;
        function<void(int, int, int, double)> dfs = [&](int u, int x, int y, double val) {
            if (u == n + 1) {
                ans = min(ans, val);
                RE;
            }
            dfs(u + 1, w[p[u]][2], w[p[u]][3], val + calc(x, y, w[p[u]][0], w[p[u]][1]) / s);
            dfs(u + 1, w[p[u]][0], w[p[u]][1], val + calc(x, y, w[p[u]][2], w[p[u]][3]) / s);
        };
        dfs(1, 0, 0, res);
    } while (next_permutation(p.begin() + 1, p.end()));

    cout << setprecision(12) << fixed << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}