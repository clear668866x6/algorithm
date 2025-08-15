#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

    V<V<char>> s(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    queue<array<int, 3>> q;
    V<V<int>> vis(n + 1, V<int>(m + 1, 0)), val(n + 1, V<int>(m + 1, 1e18));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == 'E') {
                q.push({i, j, 0});
                vis[i][j] = 1;
                val[i][j] = 0;
            }
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    while (sz(q)) {
        auto [x, y, step] = q.front();
        q.pop();

        FOR(i, 0, 3) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#' || val[a][b] < step + 1 || vis[a][b]) continue;
            val[a][b] = min(val[a][b], step + 1);
            vis[a][b] = 1;
            q.push({a, b, step + 1});
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '.') {
                int t = 1e18, id = 0;
                FOR(k, 0, 3) {
                    int a = i + dx[k], b = j + dy[k];
                    if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#') continue;
                    if (t > val[a][b]) {
                        t = val[a][b];
                        id = k;
                    }
                }

                if (id == 0) {
                    s[i][j] = '^';
                } else if (id == 1) {
                    s[i][j] = '>';
                } else if (id == 2) {
                    s[i][j] = 'v';
                } else {
                    s[i][j] = '<';
                }
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << s[i][j];
        }
        cout << endl;
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
