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
    V<V<int>> d1(n + 1, V<int>(n + 1, 1e18)), d2(n + 1, V<int>(n + 1, 1e18));

    FOR(i, 1, n) d1[i][i] = d2[i][i] = 0;

    set<array<int, 2>> s;

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        s.insert({a, b});
        d1[a][b] = d1[b][a] = min<int>(d1[a][b], 1);
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            int x = i, y = j;
            if (x > y) swap(x, y);
            if (!s.count({x, y})) {
                d2[x][y] = d2[y][x] = min<int>(d2[x][y], 1);
            }
        }
    }

    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }

    if (d1[1][n] == 1e18 || d2[1][n] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << max(d1[1][n], d2[1][n]) << endl;
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