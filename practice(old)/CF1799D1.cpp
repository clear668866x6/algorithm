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
/*

中一个 CPU 是 a_p ，另一个是 j 的最优方案。假

*/
void solve() {
    int n, m;
    cin >> n >> m;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    V<int> c(m + 1, 0), d(m + 1, 0);
    FOR(i, 1, m) cin >> c[i];
    FOR(i, 1, m) cin >> d[i];

    V<V<int>> f(n + 1, V<int>(m + 1, 1e18));
    f[0][0] = 0;

    FOR(i, 1, n) {
        FOR(j, 0, m) {
            if (w[i - 1] != w[i]) {
                f[i][j] = min(f[i][j], f[i - 1][j] + c[w[i]]);
            } else {
                f[i][j] = min(f[i][j], f[i - 1][j] + d[w[i]]);
            }
            if (j != w[i]) {
                f[i][w[i - 1]] = min(f[i][w[i - 1]], f[i - 1][j] + c[w[i]]);
            } else {
                f[i][w[i - 1]] = min(f[i][w[i - 1]], f[i - 1][j] + d[w[i]]);
            }
        }
    }

    int ans = 1e18;

    FOR(i, 0, m) {
        ans = min(ans, f[n][i]);
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
