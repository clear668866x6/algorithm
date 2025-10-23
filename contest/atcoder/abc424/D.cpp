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
    int n, m;
    cin >> n >> m;
    V<V<char>> s(n, V<char>(m, 0));
    V<V<int>> w(n, V<int>(m, 0));
    V<int> row(n, 0);
    FOR(i, 0, n - 1) {
        FOR(j, 0, m - 1) {
            cin >> s[i][j];
            if (s[i][j] == '#') {
                row[i] |= (1 << j);
            }
        }
    }

    V<V<int>> f((1 << m), V<int>(n, 1e18));

    FOR(cur, 0, (1 << m) - 1) {
        if ((cur | row[0]) != row[0]) continue;
        int cost = __builtin_popcount(row[0]) - __builtin_popcount(cur);
        f[cur][0] = cost;
    }

    FOR(i, 1, n - 1) {
        FOR(pre, 0, (1 << m) - 1) {
            if ((pre | row[i - 1]) != row[i - 1]) continue;
            FOR(cur, 0, (1 << m) - 1) {
                if ((cur | row[i]) != row[i]) continue;
                bool ff = false;
                FOR(j, 0, m - 2) {
                    if ((pre & (1 << j)) && (pre & (1 << (j + 1))) && (cur & (1 << j)) && (cur & (1 << (j + 1)))) {
                        ff = 1;
                        break;
                    }
                }
                if (ff) continue;
                int cost = __builtin_popcount(row[i]) - __builtin_popcount(cur);
                f[cur][i] = min(f[cur][i], f[pre][i - 1] + cost);
            }
        }
    }

    int ans = 1e18;

    FOR(i, 0, (1 << m) - 1) {
        ans = min(ans, f[i][n - 1]);
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
