#include <algorithm>
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
    V<int> c(n + 1, 0);
    FOR(i, 1, n) cin >> c[i];
    V<string> p(n + 1);
    V<string> rev(n + 1);
    FOR(i, 1, n) {
        cin >> p[i];
        rev[i] = p[i];
        reverse(ALL(rev[i]));
        p[i] = ' ' + p[i];
        rev[i] = ' ' + rev[i];
    }

    V<V<int>> f(n + 1, V<int>(2, 1e18));
    f[0][0] = f[0][1] = 0;

    FOR(i, 1, n) {
        if (p[i - 1] <= p[i]) {
            f[i][0] = min(f[i][0], f[i - 1][0]);
        }
        if (rev[i - 1] <= p[i]) {
            f[i][0] = min(f[i][0], f[i - 1][1]);
        }
        if (p[i - 1] <= rev[i]) {
            f[i][1] = min(f[i][1], f[i - 1][0] + c[i]);
        }
        if (rev[i - 1] <= rev[i]) {
            f[i][1] = min(f[i][1], f[i - 1][1] + c[i]);
        }
    }

    int ans = min(f[n][0], f[n][1]);
    if (ans == 1e18) ans = -1;

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