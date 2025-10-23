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
    V<int> x(n + 1, 0);
    FOR(i, 1, n) cin >> x[i];

    V<int> pre(n + 1, 0);
    FOR(i, 1, n) pre[i] = pre[i - 1] + x[i];
    V<V<int>> f(n + 1, V<int>(n + 1, 0));
    map<int, int> mp;

    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        mp[x] += y;
    }

    FOR(i, 1, n) {
        FOR(j, 0, i - 1) f[i][0] = max(f[i][0], f[i - 1][j]);
        FOR(j, 1, i) {
            f[i][j] = max(f[i - 1][j - 1] + x[i] + mp[j], f[i][j]);
        }
    }

    int ans = 0;

    FOR(i, 1, n) ans = max(ans, f[n][i]);

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