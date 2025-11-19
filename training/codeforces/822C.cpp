#include <algorithm>
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
    int n, x;
    cin >> n >> x;
    V<int> l(n + 1, 0), r(n + 1, 0), w(n + 1, 0);
    map<int, V<array<int, 2>>> mpl, mpr;
    map<int, V<int>> pre, suf, p1, p2;

    FOR(i, 1, n) {
        int a, b, c;
        cin >> a >> b >> c;
        l[i] = a, r[i] = b, w[i] = c;
        mpl[b - a + 1].pb({a, i});
        mpr[b - a + 1].pb({b, i});
    }

    for (auto &[x, y] : mpl) sort(ALL(y));
    for (auto &[x, y] : mpr) sort(ALL(y));

    for (auto [x, y] : mpl) {
        suf[x].resize(sz(y));
        int mn = 1e18;
        FORD(i, 0, sz(y) - 1) {
            mn = min(mn, w[y[i][1]]);
            suf[x][i] = mn;
        }
        FOR(i, 0, sz(y) - 1) {
            p1[x].eb(y[i][0]);
        }
    }

    for (auto [x, y] : mpr) {
        pre[x].resize(sz(y));
        int mn = 1e18;
        FOR(i, 0, sz(y) - 1) {
            mn = min(mn, w[y[i][1]]);
            pre[x][i] = mn;
            p2[x].eb(y[i][0]);
        }
    }

    int ans = 1e18;

    FOR(i, 1, n) {
        int len = r[i] - l[i] + 1;
        int t = x - len;
        if (!p1[t].empty()) {
            auto it = upper_bound(ALL(p1[t]), r[i]);
            if (it != p1[t].end()) {
                int idx = it - p1[t].begin();
                ans = min(ans, w[i] + suf[t][idx]);
            }
        }
        if (!p2[t].empty()) {
            auto it2 = lower_bound(ALL(p2[t]), l[i]);
            if (it2 != p2[t].begin()) {
                it2--;
                int idx = it2 - p2[t].begin();
                ans = min(ans, w[i] + pre[t][idx]);
            }
        }
    }

    if (ans == 1e18) ans = -1;

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