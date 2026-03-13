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
// 对于这种行列都需要满足某种性质的题，可以一步一步的来做，而不是一下子做，先处理行，再处理列。

void solve() {
    int n;
    cin >> n;
    V<V<char>> s(n + 1, V<char>(n + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> s[i][j];
        }
    }

    V<V<int>> f(n + 1, V<int>(n + 1, 1e18)), g(n + 1, V<int>(n + 2, 1e18));

    FOR(i, 0, n) f[0][i] = g[0][i] = 0;

    FOR(i, 1, n) {
        int t = 0;
        FOR(j, 0, n) {
            if (s[i][j] == '.') t++;
        }
        f[i][0] = min(f[i][0], g[i - 1][0] + t);
        FOR(j, 1, n) {
            if (s[i][j] == '#') t++;
            if (s[i][j] == '.') t--;
            f[i][j] = min(f[i][j], g[i - 1][j] + t);
        }
        FORD(j, 0, n) g[i][j] = min(g[i][j + 1], f[i][j]);
    }

    int ans = 1e18;

    FOR(i, 0, n) ans = min(ans, f[n][i]);

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