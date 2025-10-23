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
    V<V<char>> w(n + 1, V<char>(m + 1));

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    auto get = [&](int x, int y) { return (x - 1) * m + y; };

    int tot = n * m;
    V<V<int>> d(tot + 1, V<int>(tot + 1, 1e18));

    FOR(i, 1, tot) d[i][i] = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (w[i][j] == '.') {
                int x = get(i, j);
                FOR(k, 0, 3) {
                    int a = dx[k] + i, b = dy[k] + j;
                    if (a < 1 || b < 1 || a > n || b > m || w[a][b] == '#') continue;
                    int y = get(a, b);
                    d[x][y] = d[y][x] = min<int>(d[x][y], 1);
                }
            }
        }
    }

    FOR(k, 1, tot) {
        FOR(i, 1, tot) {
            FOR(j, 1, tot) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;

    FOR(x1, 1, n) {
        FOR(y1, 1, m) {
            if (w[x1][y1] == '.') {
                FOR(x2, 1, n) {
                    FOR(y2, 1, m) {
                        if (w[x2][y2] == '.') {
                            int x = get(x1, y1), y = get(x2, y2);
                            ans = max(ans, d[x][y]);
                        }
                    }
                }
            }
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