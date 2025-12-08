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
    int n, m, k;
    cin >> n >> m >> k;
    V<V<int>> odd(n + 1, V<int>(m + 1, 0)), even(n + 1, V<int>(m + 1, 0));
    FOR(i, 1, k) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        odd[x1][y1] = 1;
        even[x2][y2] = 1;
    }

    array<int, 4> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};

    V<V<V<int>>> d(n + 1, V<V<int>>(m + 1, V<int>(2, 1e18)));

    d[1][1][0] = d[1][1][1] = 1;

    queue<array<int, 2>> q;
    q.push({1, 1});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m || (odd[a][b] && even[a][b])) continue;
            int t1 = d[x][y][0] + 1;
            if (t1 & 1) {
                if (odd[a][b]) {
                    if (d[a][b][1] > d[x][y][0] + 1) {
                        d[a][b][1] = d[x][y][0] + 1;
                        q.push({a, b});
                    }
                } else {
                    if (d[a][b][0] > d[x][y][0] + 1) {
                        d[a][b][0] = d[x][y][0] + 1;
                        q.push({a, b});
                    }
                }
            } else {
                if (even[a][b]) {
                    if (d[a][b][1] > d[x][y][0] + 1) {
                        d[a][b][1] = d[x][y][0] + 1;
                        q.push({a, b});
                    }
                } else {
                    if (d[a][b][0] > d[x][y][0] + 1) {
                        d[a][b][0] = d[x][y][0] + 1;
                        q.push({a, b});
                    }
                }
            }

            int t2 = d[x][y][1] + 1;

            if (t2 & 1) {
                if (!odd[a][b]) {
                    if (d[a][b][1] > d[x][y][1] + 1) {
                        d[a][b][1] = d[x][y][1] + 1;
                        q.push({a, b});
                    }
                }
            } else {
                if (!even[a][b]) {
                    if (d[a][b][1] > d[x][y][1] + 1) {
                        d[a][b][1] = d[x][y][1] + 1;
                        q.push({a, b});
                    }
                }
            }
        }
    }

    int ans = min(d[n][m][0], d[n][m][1]);

    if (ans == 1e18) ans = 0;

    cout << ans - 1;
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