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
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    V<V<V<int>>> f(n + 1, V<V<int>>(35, V<int>(2, -1e18)));

    f[0][0][1] = 0;

    FOR(i, 1, n) {
        FOR(j, 0, min<int>(33, i)) {
            f[i][j][1] = max<int>(f[i][j][1], f[i - 1][j][1] + (a[i] / (1LL << j)) - k);
            if (j >= 1) {
                f[i][j][1] = max<int>(f[i][j][1], f[i - 1][j][0] + (a[i] / (1LL << j)) - k);
            }
            if (j - 1 >= 0) {
                f[i][j][0] = max<int>(f[i][j][0], f[i - 1][j - 1][1] + (a[i] / (1LL << j)));
            }
            if (j - 1 >= 1) {
                f[i][j][0] = max<int>(f[i][j][0], f[i - 1][j - 1][0] + (a[i] / (1LL << j)));
            }
        }
        if (i > 32) {
            f[i][33][0] = max({f[i][33][0], f[i - 1][33][1], f[i - 1][33][0]});
            f[i][33][1] = max({f[i][33][1], f[i - 1][33][1], f[i - 1][33][0]});
        }
    }

    int ans = -1e18;

    FOR(i, 0, 33) {
        ans = max({ans, f[n][i][0], f[n][i][1]});
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
