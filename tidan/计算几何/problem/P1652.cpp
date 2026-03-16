#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    V<int> x(n + 1, 0), y(n + 1, 0), r(n + 1, 0);
    FOR(i, 1, n) cin >> x[i];
    FOR(i, 1, n) cin >> y[i];
    FOR(i, 1, n) cin >> r[i];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    auto dist = [&](int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    };

    int ans = 0;

    FOR(i, 1, n) {
        int p1 = dist(x1, y1, x[i], y[i]), p2 = dist(x2, y2, x[i], y[i]);
        int t1 = p1 - r[i] * r[i], t2 = p2 - r[i] * r[i];
        if (t1 < 0 && t2 > 0 || (t1 > 0 && t2 < 0)) {
            ans++;
        }
    }

    cout << ans;
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