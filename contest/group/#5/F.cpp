#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int n, m;
    cin >> n >> m;
    V<V<int>> w(n + 1, V<int>(m + 1, 0));

    int mn = 1e18;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
            mn = min(mn, w[i][j]);
        }
    }

    V<V<int>> f(n + 1, V<int>(m + 1, 1e18));

    int ans = 1e18;

    FOR(x, 1, n) {
        FOR(y, 1, m) {
            int p = w[x][y] - x - y + 2;
            if (w[1][1] - p < 0) continue;
            f[1][1] = (w[1][1] - p);
            FOR(i, 1, n) {
                FOR(j, 1, m) {
                    int v = w[i][j] - p - i - j + 2;
                    if (v < 0) continue;
                    if (i - 1) {
                        f[i][j] = min(f[i][j], f[i - 1][j] + v);
                    }
                    if (j - 1) {
                        f[i][j] = min(f[i][j], f[i][j - 1] + v);
                    }
                }
            }
            ans = min(ans, f[n][m]);
            FOR(i, 0, n) {
                FOR(j, 0, m) {
                    f[i][j] = 1e18;
                }
            }
        }
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
