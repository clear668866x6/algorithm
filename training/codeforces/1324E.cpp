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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    V<V<int>> f(n + 1, V<int>(h + 1, -1e18));
    f[0][0] = 0;

    FOR(i, 1, n) {
        FOR(j, 0, h - 1) {
            int t = (j + a[i]) % h;
            f[i][t] = max(f[i][t], f[i - 1][j]);
            if (t >= l && t <= r) {
                f[i][t] = max(f[i][t], f[i - 1][j] + 1);
            }
            t = ((j + a[i] - 1) % h + h) % h;
            f[i][t] = max(f[i][t], f[i - 1][j]);
            if (t >= l && t <= r) {
                f[i][t] = max(f[i][t], f[i - 1][j] + 1);
            }
        }
    }

    int ans = 0;

    FOR(i, 0, h - 1) {
        ans = max(ans, f[n][i]);
    }
    cout << ans;
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