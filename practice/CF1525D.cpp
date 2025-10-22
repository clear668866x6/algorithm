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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<int> c0, c1;

    FOR(i, 1, n) {
        if (w[i] == 1) {
            c1.eb(i);
        } else {
            c0.eb(i);
        }
    }

    int s0 = sz(c0), s1 = sz(c1);

    V<V<int>> f(n + 1, V<int>(n + 1, 0)), g(n + 1, V<int>(n + 1, 1e18));
    FOR(i, 0, n) {
        g[0][i] = 0;
    }

    FOR(i, 1, s1) {

        FOR(j, i, s0) {
            f[i][j] = g[i - 1][j - 1] + abs(c1[i - 1] - c0[j - 1]);
        }
        FOR(j, i, s0) {
            g[i][j] = min(f[i][j], g[i][j - 1]);
        }
    }

    int ans = 1e18;

    FOR(i, s1, s0) ans = min(ans, f[s1][i]);

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