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
    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), d(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) cin >> c[i];
    FOR(i, 1, n) cin >> d[i];

    V<V<int>> f(n + 1, V<int>(n + 1, 1e18));

    f[0][0] = 0;

    // V<int> c1,c2(n + 1, 1e18);
    FOR(i, 1, n) {
        FOR(j, 1, i) {
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + b[i] + d[j]);
        }
        FOR(j, 0, i) {
            f[i][j] = min(f[i][j], f[i - 1][j] + a[i] + c[i - j]);
        }
    }

    int ans = 1e18;

    FOR(i, 0, n) {
        ans = min(ans, f[n][i]);
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