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
    int n, m, k;
    cin >> n >> m >> k;
    V<V<int>> w(n + 1, V<int>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    V<V<V<int>>> f(n + 1, V<V<int>>(m + 1, V<int>(m + 1, 1e18)));

    f[0][1][0] = f[1][0][0] = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            int mn = 1e18;

            FOR(p1, 0, m - 1) {
                mn = min(mn, f[i - 1][j][p1]);
            }

            FOR(p1, 0, m - 1) {
                f[i][j][p1] = min(f[i][j][p1], mn + w[i][((j + p1 - 1) % m + m) % m + 1] + k * p1);
                f[i][j][p1] = min(f[i][j][p1], f[i][j - 1][p1] + w[i][((j + p1 - 1) % m + m) % m + 1]);
            }
        }
    }

    int ans = 1e18;

    FOR(i, 0, m - 1) ans = min(ans, f[n][m][i]);

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
