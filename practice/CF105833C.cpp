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
    V<int> h(n + 1, 0), d(n + 1, 0), c(n + 1, 0);
    FOR(i, 1, n) cin >> h[i];
    FOR(i, 1, n) cin >> d[i];
    FOR(i, 1, n) cin >> c[i];

    V f(n + 2, V<int>(5010, -1e18));

    f[n + 1][0] = 0;

    FORD(i, 1, n) {
        FOR(j, 0, 5000) {
            if (f[i + 1][j] == -1e18) continue;
            int nj = min<int>(5000, j + d[i]);
            int t1 = min(h[i], nj);
            int t2 = min(h[i], j);
            f[i][nj] = max(f[i][nj], f[i + 1][j] + t1 - c[i]);
            f[i][j] = max(f[i][j], f[i + 1][j] + t2);
        }
    }

    int ans = 0;

    FOR(i, 0, 5000) {
        ans = max(ans, f[1][i]);
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