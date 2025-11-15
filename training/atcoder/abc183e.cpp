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

constexpr int mod = 1e9 + 7;

void solve() {

    int n, m;
    cin >> n >> m;
    V<V<char>> s(n + 1, V<char>(m + 1, '#'));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    V<V<int>> f(n + 1, V<int>(m + 1, 0));
    V<V<int>> p1(n + 1, V<int>(m + 1, 0)), p2(n + 1, V<int>(m + 1, 0)), p3(n + 1, V<int>(m + 1, 0));
    f[1][1] = 1;

    FOR(i, 1, n) {

        FOR(j, 1, m) {
            if (s[i][j] == '#') continue;
            p1[i][j] = p1[i - 1][j] + f[i - 1][j];
            p2[i][j] = p2[i][j - 1] + f[i][j - 1];
            p3[i][j] = p3[i - 1][j - 1] + f[i - 1][j - 1];
            f[i][j] += p1[i][j];
            f[i][j] += p2[i][j];
            f[i][j] += p3[i][j];
            f[i][j] %= mod;
            // FOR(k, 1, i) {
            //     if (s[i - k][j] == '#') {
            //         break;
            //     }
            //     f[i][j] += f[i - k][j];
            // }
            // FOR(k, 1, j) {
            //     if (s[i][j - k] == '#') {
            //         break;
            //     }
            //     f[i][j] += f[i][j - k];
            // }

            // FOR(k, 1, j) {
            //     if (s[i - k][j - k] == '#') {
            //         break;
            //     }
            //     f[i][j] += f[i - k][j - k];
            // }
        }
    }
    cout << f[n][m];
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