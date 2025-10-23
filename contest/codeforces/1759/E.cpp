#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
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
    int n, h;
    cin >> n >> h;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    sort(ALL(w));

    V<V<V<int>>> f(n + 1, V<V<int>>(3, V<int>(2, 0)));

    f[0][2][1] = h;

    FOR(i, 1, n) {
        FORD(j, 0, 2) {
            FORD(k, 0, 1) {
                FOR(a, 0, j) {
                    FOR(b, 0, k) {
                        int t = max<int>(1, a * 2) * max<int>(1, b * 3);
                        if (f[i - 1][j][k] * t > w[i]) {
                            f[i][j - a][k - b] =
                                max(f[i][j - a][k - b], f[i - 1][j][k] * t + w[i] / 2);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        // cout << f[i][0][0] << endl;

        if (f[i][0][0] > w[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
