#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0), b(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    if (accumulate(ALL(a), 0ll) < m) {
        cout << -1 << endl;
        RE;
    }

    V<int> c, d;

    FOR(i, 1, n) {
        if (b[i] == 1) {
            c.eb(a[i]);
        } else {
            d.eb(a[i]);
        }
    }

    sort(RALL(c)), sort(RALL(d));

    int n1 = sz(c), n2 = sz(d);

    V<int> p1(n1 + 1, 0), p2(n2 + 1, 0);

    FOR(i, 1, n1) p1[i] = p1[i - 1] + c[i - 1];
    FOR(i, 1, n2) p2[i] = p2[i - 1] + d[i - 1];

    int ans = 1e18;

    FOR(i, 0, n1) {
        int t = p1[i];
        auto it = lower_bound(ALL(p2), m - t);
        if (it != p2.end()) {
            ans = min(ans, (it - p2.begin()) * 2 + i);
        }
    }

    cout << ans << endl;
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
