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
    int n, m, l;
    cin >> n >> m >> l;

    V<int> w(n, 0);

    FOR(i, 0, n - 1) cin >> w[i];

    V<V<int>> f(n + 1, V<int>(m, 1e18)), g(n + 1, V<int>(m, 0));

    V<V<int>> gg(l);

    FOR(i, 0, n - 1) {
        gg[i % l].eb(w[i]);
    }

    FOR(i, 1, l) {
        FOR(j, 0, m - 1) {
            int c = 0;
            for (auto x : gg[i - 1]) {
                c += (j - x + m) % m;
            }
            g[i][j] = c;
        }
    }

    f[0][0] = 0;

    FOR(i, 1, l) {
        FOR(j, 0, m - 1) {
            FOR(k, 0, m - 1) {
                f[i][j] = min(f[i - 1][(j - k + m) % m] + g[i][k], f[i][j]);
            }
        }
    }

    cout << f[l][0];
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