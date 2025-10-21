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
    int n, k;
    cin >> n >> k;
    V<array<int, 3>> w(n + 1);
    int c1 = 0, c2 = 0;
    FOR(i, 1, n) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = {a, b, c};
        if (b) c1++;
        if (c) c2++;
    }

    if (c1 < k || c2 < k) {
        cout << -1 << endl;
        RE;
    }

    V<int> c, d, e;
    FOR(i, 1, n) {
        if (w[i][1] && !w[i][2]) {
            c.eb(w[i][0]);
        }
        if (!w[i][1] && w[i][2]) {
            d.eb(w[i][0]);
        }
        if (w[i][1] && w[i][2]) {
            e.eb(w[i][0]);
        }
    }

    sort(ALL(c));
    sort(ALL(d));
    FOR(i, 0, min(sz(c), sz(d)) - 1) {
        e.eb(c[i] + d[i]);
    }
    sort(ALL(e));
    if (sz(e) < k) {
        cout << -1 << endl;
        RE;
    }

    int ans = 0;
    FOR(i, 0, k - 1) ans += e[i];

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