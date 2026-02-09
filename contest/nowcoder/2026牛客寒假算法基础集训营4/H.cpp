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
    int n, m, q;
    cin >> n >> m >> q;
    V<V<int>> w(n + 1, V<int>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    int ansx = 0, ansy = 0, ans = 0;
    V<V<int>> s(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            int tot = 0;
            FOR(c, -2, 2) {
                FOR(d, -2, 2) {
                    int a = i + c, b = j + d;
                    if (a < 1 || b < 1 || a > n || b > m) continue;
                    int t = abs(i - a) + abs(b - j);
                    if (t <= 2) {
                        tot += w[a][b];
                    }
                }
            }
            s[i][j] = tot;
            if (s[i][j] > ans) {
                ans = s[i][j];
                ansx = i, ansy = j;
            }
        }
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        w[x][y] += z;
        FOR(c, -2, 2) {
            FOR(d, -2, 2) {
                int a = x + c, b = y + d;
                if (a < 1 || b < 1 || a > n || b > m) continue;
                int t = abs(x - a) + abs(b - y);
                if (t <= 2) {
                    s[a][b] += z;
                    if (s[a][b] > ans) {
                        ans = s[a][b];
                        ansx = a, ansy = b;
                    }
                }
            }
        }
        cout << ansx << ' ' << ansy << endl;
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