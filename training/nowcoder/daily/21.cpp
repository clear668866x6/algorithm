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
    int n, m, p;
    cin >> n >> m >> p;

    V<V<char>> s(n + 1, V<char>(m + 1, 0));
    int cnt = 0;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == '0') cnt++;
        }
    }

    V<V<V<char>>> t(p + 1, V<V<char>>(n + 1, V<char>(m + 1, 0)));

    FOR(i, 1, p) {
        FOR(j, 1, n) {
            FOR(k, 1, m) {
                cin >> t[i][j][k];
            }
        }
    }
    int ans = 1e18;
    V<int> res;

    FOR(state, 0, (1 << p) - 1) {
        V<int> c;
        FOR(j, 0, p - 1) {
            if (state >> j & 1) {
                c.eb(j + 1);
            }
        }
        V<V<int>> tot(n + 1, V<int>(m + 1, 0));
        for (auto x : c) {
            FOR(i, 1, n) {
                FOR(j, 1, m) {
                    if (t[x][i][j] == '1') {
                        tot[i][j] = 1;
                    }
                }
            }
        }

        bool f = false;

        FOR(i, 1, n) {
            FOR(j, 1, m) {
                if (tot[i][j] == 1 && s[i][j] == '1') {
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }

        if (!f) {
            int cc = 0;
            FOR(i, 1, n) {
                FOR(j, 1, m) {
                    if (tot[i][j]) cc++;
                }
            }
            if (cc == cnt) {
                if (ans > sz(c)) {
                    res.clear();
                    res.eb(ans);
                    ans = sz(c);
                    for (auto x : c) res.eb(x);
                }
            }
        }
    }

    if (ans == 1e18) {
        cout << -1;
        RE;
    }

    cout << ans << endl;
    FOR(i, 1, sz(res) - 1) cout << res[i] << ' ';
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
