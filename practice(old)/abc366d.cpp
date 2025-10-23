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
    V<V<V<int>>> w(n + 1, V<V<int>>(n + 1, V<int>(n + 1, 0)));
    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> w[k][i][j];
            }
        }
    }

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                w[k][i][j] += w[k - 1][i][j];
            }
        }
    }

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                w[k][i][j] += w[k][i - 1][j];
            }
        }
    }

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                w[k][i][j] += w[k][i][j - 1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int k1, x1, y1, k2, x2, y2;
        cin >> k1 >> k2 >> x1 >> x2 >> y1 >> y2;

        int ans = 0;

        ans = w[k2][x2][y2] - w[k1 - 1][x2][y2] - w[k2][x1 - 1][y2] - w[k2][x2][y1 - 1] + w[k1 - 1][x1 - 1][y2] +
              w[k1 - 1][x2][y1 - 1] + w[k2][x1 - 1][y1 - 1] - w[k1 - 1][x1 - 1][y1 - 1];

        cout << ans << endl;
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