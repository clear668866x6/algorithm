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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<V<V<i64>>> f(2, V<V<i64>>(203, V<i64>(2, 0)));
    int mod = 998244353;

    if (w[1] > 0)
        f[1][w[1]][0] = 1;
    else {
        FOR(i, 1, 200) f[1][i][0] = 1;
    }

    FOR(i, 2, n) {
        int cur = i % 2;
        int lst = (i - 1) % 2;

        FOR(j, 0, 200) {
            f[cur][j][0] = f[cur][j][1] = 0;
        }

        FOR(j, 1, 200) {
            f[lst][j][0] += f[lst][j - 1][0];
            f[lst][j][1] += f[lst][j - 1][1];
        }

        FOR(j, 1, 200) {
            if (w[i] > 0 && w[i] != j) continue;
            f[cur][j][1] += f[lst][j][0] - f[lst][j - 1][0];
            f[cur][j][1] += f[lst][200][1] - f[lst][j - 1][1];
            f[cur][j][0] += f[lst][j - 1][0] - f[lst][0][0];
            f[cur][j][0] += f[lst][j - 1][1] - f[lst][0][1];
            f[cur][j][1] %= mod, f[cur][j][0] %= mod;
        }
    }

    i64 ans = 0;

    FOR(i, 1, 200)(ans += f[n % 2][i][1]) %= mod;

    cout << (ans + mod) % mod << endl;
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