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
    int n, t;
    cin >> n >> t;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    V<int> b, c;
    FOR(i, 1, n / 2 + 1) b.eb(a[i]);
    FOR(i, n / 2 + 2, n) c.eb(a[i]);
    V<int> d, e;
    function<void(int, int)> dfs1 = [&](int u, int tot) {
        if (u == sz(b)) {
            if (tot <= t) {
                d.eb(tot);
            }
            RE;
        }

        dfs1(u + 1, tot);
        dfs1(u + 1, tot + b[u]);
    };

    dfs1(0, 0);

    int mx = *min_element(ALL(d));

    function<void(int, int)> dfs2 = [&](int u, int tot) {
        if (tot + mx > t) RE;
        if (u == sz(c)) {
            if (tot <= t) {
                e.eb(tot);
            }
            RE;
        }

        dfs2(u + 1, tot);
        dfs2(u + 1, tot + c[u]);
    };

    dfs2(0, 0);

    sort(ALL(d)), sort(ALL(e));

    int ans = 0;

    FOR(i, 0, sz(d) - 1) {
        auto it = upper_bound(ALL(e), t - d[i]);
        if (it != e.begin()) {
            ans = max(ans, d[i] + *prev(it));
        } else {
            if (d[i] <= t) {
                ans = max(ans, d[i]);
            }
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