#include <bits/stdc++.h>
#include <iomanip>
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
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    s = ' ' + s;

    if (n > 50) {
        cout << "1.000";
        RE;
    }

    double p = a / 100.0;

    if (!q) {
        double ans = 1;
        FOR(i, 1, n) {
            if (s[i] == '0') {
                ans *= p;
            } else {
                ans *= (1 - p);
            }
        }
        cout << fixed << setprecision(3) << ans;
    } else {
        V<V<double>> f(n + 1, V<double>(55, 0));

        f[0][0] = 1;

        FOR(i, 1, n) {
            FOR(j, 0, i) {
                if (s[i] == '1') {
                    if (j - 1 >= 0) {
                        f[i][j] += (f[i - 1][j - 1] * p);
                    }
                    f[i][j] += (f[i - 1][j] * (1 - p));
                } else {
                    if (j - 1 >= 0) {
                        f[i][j] += (f[i - 1][j - 1] * (1 - p));
                    }
                    f[i][j] += (f[i - 1][j] * p);
                }
            }
        }

        double ans = 0;

        FOR(i, q, n) ans += f[n][i];

        cout << fixed << setprecision(3) << ans;
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