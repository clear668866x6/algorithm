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
    int n, m;
    cin >> n >> m;

    V<int> a(n + 1, 0);

    FOR(i, 1, n) cin >> a[i];

    V<V<array<int, 3>>> g(n + 1);

    FOR(i, 1, m) {
        int e, t, p;
        cin >> e >> t >> p;
        g[e].pb({p, t, i});
    }

    V<int> ans;
    int sum = 0;

    FOR(i, 1, n) {
        int k = sz(g[i]);
        V<V<int>> f(k + 2, V<int>(211, 1e18));
        f[1][0] = 0;

        FOR(j, 1, k) {
            f[j + 1] = f[j];
            auto [p, t, id] = g[i][j - 1];
            FOR(tt, 0, 100) {
                int nk = min<int>(100, tt + p);
                f[j + 1][nk] = min(f[j + 1][nk], f[j][tt] + t);
            }
        }

        // cout << i << ' ' << f[k][100] << endl;

        sum += f[k + 1][100];

        if (sum > a[i]) {
            cout << -1 << endl;
            RE;
        }

        int nk = 100;

        FORD(j, 1, k) {
            auto [p, t, id] = g[i][j - 1];
            if (f[j + 1][nk] == f[j][nk]) continue;
            ans.eb(id);
            FOR(tt, 0, 100) {
                int nd = min<int>(100, tt + p);
                if (nd == nk && f[j + 1][nd] == f[j][tt] + t) {
                    nk = tt;
                    break;
                }
            }
        }
    }

    cout << sz(ans) << endl;
    for (auto x : ans) cout << x << ' ';
    cout << endl;
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
