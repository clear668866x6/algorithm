#include <bits/stdc++.h>
#include <cstring>
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
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> w[i][j];
        }
    }
    int mod = 1e9 + 7;

    auto calc = [&](V<V<int>> a, V<V<int>> b) {
        V<V<int>> c(n + 1, V<int>(n + 1, 0));

        FOR(k, 1, n) {
            FOR(i, 1, n) {
                FOR(j, 1, n) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    };

    V<V<int>> res(n + 1, V<int>(n + 1, 0));

    FOR(i, 1, n) res[i][i] = 1;

    while (m) {
        if (m & 1) res = calc(res, w);
        w = calc(w, w);
        m >>= 1;
    }

    int ans = 0;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            (ans += res[i][j]) %= mod;
        }
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