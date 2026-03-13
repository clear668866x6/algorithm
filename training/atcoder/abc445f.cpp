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

struct Juzhen {

    V<V<int>> mul(V<V<int>> a, V<V<int>> b) {
        int n = sz(a) - 1;
        V<V<int>> c(n + 1, V<int>(n + 1, 1e18));
        FOR(k, 1, n) {
            FOR(i, 1, n) {
                FOR(j, 1, n) {
                    c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
        return c;
    }

    V<V<int>> qmi(V<V<int>> a, int b) {
        int n = sz(a) - 1;
        V<V<int>> ans(n + 1, V<int>(n + 1, 1e18));

        FOR(i, 1, n) ans[i][i] = 0;

        while (b) {
            if (b & 1) ans = mul(ans, a);
            a = mul(a, a);
            b /= 2;
        }

        return ans;
    }

} A;

void solve() {
    int n, k;
    cin >> n >> k;

    V<V<int>> d(n + 1, V<int>(n + 1, 1e18));

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            int x;
            cin >> x;
            d[i][j] = min(d[i][j], x);
        }
    }

    V<V<int>> ans = A.qmi(d, k);

    FOR(s, 1, n) {
        cout << ans[s][s] << endl;
    }
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