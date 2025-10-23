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

    int mod = 1e9 + 7;
    V<V<int>> f(n + 1, V<int>(n + 1, 0));
    f[0][0] = 1;

    FOR(i, 1, n) {
        V<V<int>> g(n + 1, V<int>(n + 1, 0));
        int x = w[i];
        FOR(j, 0, n) {
            FOR(k, 0, n) {
                int c = f[j][k];
                if (!c) continue;
                g[j][k] = (g[j][k] + c) % mod;
                if (j <= x) {
                    g[x][k] = (g[x][k] + c) % mod;
                } else if (k <= x) {
                    g[j][x] = (g[j][x] + c) % mod;
                }
            }
        }
        f = g;
    }

    int ans = 0;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            ans = (ans + f[i][j]) % mod;
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
