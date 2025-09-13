#include <bits/stdc++.h>
#include <numeric>
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

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    int N = 1e3;

    V<int> g(1e4 + 10, 1e18);
    g[1] = 0;

    FOR(i, 1, N) {
        FOR(j, 1, i) {
            g[i + i / j] = min(g[i + i / j], g[i] + 1); // 这个最大也就12,所以k最大也就是12n
        }
    }

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;

        V<int> b(n + 1, 0), c(n + 1, 0);

        FOR(i, 1, n) cin >> b[i];
        FOR(i, 1, n) cin >> c[i];

        if (k >= accumulate(ALL(b), 0LL)) {
            cout << accumulate(ALL(c), 0LL) << endl;
        } else {
            V<int> f(k + 1, 0);

            FOR(i, 1, n) {
                FORD(j, g[b[i]], k) {
                    f[j] = max(f[j], f[j - g[b[i]]] + c[i]);
                }
            }

            cout << f[k] << endl;
        }
    };

    while (Task--) {
        solve();
    }

    return 0;
}
