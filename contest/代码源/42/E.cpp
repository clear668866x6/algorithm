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
    V<int> a(n + 1, 0), b(m + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    V<int> p(n + 1, 0);
    FOR(i, 2, n) cin >> p[i];

    V<int> w(n + 1, 0);

    w[1] = 1;

    FOR(i, 2, n) w[i] = w[p[i]] + i;

    V<V<int>> f(n + 1, V<int>(m + 1, 0));

    int tot = 0;

    FOR(i, 1, n) tot += a[i] * w[i];

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] = max(f[i][j], f[i][j - 1]);
            f[i][j] = max(f[i][j], f[i - 1][j - 1] + (b[j] - a[i]) * w[i]);
        }
    }

    cout << tot + f[n][m] << endl;
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