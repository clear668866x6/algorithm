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
    int n, x, y;
    cin >> n >> x >> y;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    int mn = 0, mx = 1e18;
    FOR(i, 1, n) mn = max(mn, w[i] * x);
    FOR(i, 1, n) mx = min(mx, w[i] * y);

    int base = (w[1] * x) % (y - x);
    FOR(i, 2, n) {
        if ((w[i] * x) % (y - x) != base) {
            cout << -1 << endl;
            RE;
        }
    }

    if (mn > mx) {
        cout << -1 << endl;
        RE;
    }

    if (mx < base) {
        cout << -1 << endl;
        RE;
    }

    int tot = (base + ((mx - base) / (y - x)) * (y - x));

    if (tot < mn) {
        cout << -1 << endl;
        RE;
    }
    int ans = 0;
    FOR(i, 1, n) {
        ans += (tot - w[i] * x) / (y - x);
    }
    cout << ans << endl;
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