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
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> w[i][j];
        }
    }
    V<int> a(n + 1, 0), b(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    V<V<int>> f(n + 1, V<int>(2, 1e18)), g(n + 1, V<int>(2, 1e18));
    f[1][0] = 0, f[1][1] = a[1];
    g[1][0] = 0, g[1][1] = b[1];

    FOR(i, 2, n) {
        int t1 = 0, t2 = 0, t3 = 0;
        FOR(j, 1, n) {
            if (w[i][j] == w[i - 1][j]) t1 = 1;
            if (w[i][j] == w[i - 1][j] + 1) t2 = 1;
            if (w[i][j] + 1 == w[i - 1][j]) t3 = 1;
        }
        if (!t1) {
            f[i][0] = min(f[i][0], f[i - 1][0]);
            f[i][1] = min(f[i][1], f[i - 1][1] + a[i]);
        }
        if (!t2) f[i][0] = min(f[i][0], f[i - 1][1]);
        if (!t3) f[i][1] = min(f[i][1], f[i - 1][0] + a[i]);
    }

    int ans = min(f[n][0], f[n][1]);

    FOR(i, 2, n) {
        int t1 = 0, t2 = 0, t3 = 0;
        FOR(j, 1, n) {
            if (w[j][i] == w[j][i - 1]) t1 = 1;
            if (w[j][i] == w[j][i - 1] + 1) t2 = 1;
            if (w[j][i] + 1 == w[j][i - 1]) t3 = 1;
        }
        if (!t1) {
            g[i][0] = min(g[i][0], g[i - 1][0]);
            g[i][1] = min(g[i][1], g[i - 1][1] + b[i]);
        }
        if (!t2) g[i][0] = min(g[i][0], g[i - 1][1]);
        if (!t3) g[i][1] = min(g[i][1], g[i - 1][0] + b[i]);
    }

    ans += min(g[n][0], g[n][1]);

    if (ans > 1e17) {
        ans = -1;
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
