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
    string s;
    cin >> s;
    int n = sz(s);

    // reverse(ALL(s));
    s = ' ' + s;

    V<V<int>> f(n + 2, V<int>(13, 0));
    f[0][0] = 1;

    FOR(i, 1, n) {
        if (s[i] == '?') {
            FOR(j, 0, 12) {
                FOR(k, 0, 9) {
                    int nw = j * 10 + k;
                    nw %= 13;
                    f[i][nw] += f[i - 1][j];
                    f[i][nw] %= mod;
                }
            }
        } else {
            FOR(j, 0, 12) {
                int nw = j * 10 + (s[i] - '0');
                nw %= 13;
                f[i][nw] += f[i - 1][j];
                f[i][nw] %= mod;
            }
        }
    }

    cout << f[n][5];
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