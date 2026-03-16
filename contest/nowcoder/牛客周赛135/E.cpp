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
    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, n) cin >> c[i];

    V<V<int>> f(n + 1, V<int>(6, 1e18));

    f[1][0] = 2 * c[1], f[1][1] = c[1], f[1][2] = 0, f[1][3] = b[1], f[1][4] = 2 * b[1];
    V<V<int>> d(n + 1, V<int>(6, 0));
    V<int> e(6, 0);

    FOR(i, 1, n) {
        d[i][0] = 2 * c[i], e[0] = -2;
        d[i][1] = c[i], e[1] = -1;
        d[i][2] = 0, e[2] = 0;
        d[i][3] = b[i], e[3] = 1;
        d[i][4] = 2 * b[i], e[4] = 2;
    }

    FOR(i, 0, 5) {
        if (a[1] + e[i] < 1) {
            f[1][i] = 1e18;
        }
    }

    FOR(i, 2, n) {
        FOR(j, 0, 5) {
            if (a[i] + e[j] < 1) continue;
            FOR(k, 0, 5) {
                if (a[i - 1] + e[k] < 1) continue;
                if (a[i] + e[j] == a[i - 1] + e[k]) continue;
                f[i][j] = min(f[i][j], f[i - 1][k] + d[i][j]);
            }
        }
    }

    int ans = 1e18;

    FOR(i, 0, 5) ans = min(ans, f[n][i]);

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
