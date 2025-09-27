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
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> w[i][j];
        }
    }

    V<V<int>> f(1 << n, V<int>(n + 1, 0));

    FOR(i, 1, n) {
        if (w[1][i]) {
            f[(1 << (i - 1))][1] = 1;
        }
    }

    int mod = 1e9 + 7;

    FOR(i, 2, n) {
        FOR(pre, 0, (1 << n) - 1) {
            if (f[pre][i - 1] == 0) continue;
            FOR(j, 0, n - 1) {
                if (w[i][j + 1] && !(pre >> j & 1)) {
                    (f[pre | (1 << j)][i] += f[pre][i - 1]) %= mod;
                }
            }
        }
    }

    int ans = 0;

    FOR(i, 0, (1 << n) - 1) {
        (ans += f[i][n]) %= mod;
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