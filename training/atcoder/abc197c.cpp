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

    int ans = 1e18;

    V<V<int>> pre(n + 1, V<int>(40, 0));

    FOR(i, 1, n) {
        FOR(j, 0, 32) {
            pre[i][j] = pre[i - 1][j] + (w[i] >> j & 1);
        }
    }

    FOR(state, 0, (1 << n) - 1) {
        if ((state >> (n - 1)) & 1) {
            V<int> c;
            FOR(j, 0, n - 1) {
                if (state >> j & 1) {
                    c.eb(n - j);
                }
            }
            c.eb(n + 1);
            sort(ALL(c));

            int p = 0;
            FOR(j, 1, sz(c) - 1) {
                int t = 0;
                FOR(k, 0, 32) {
                    if (pre[c[j] - 1][k] - pre[c[j - 1] - 1][k]) {
                        t |= (1ll << k);
                    }
                }
                p ^= t;
            }
            ans = min(ans, p);
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