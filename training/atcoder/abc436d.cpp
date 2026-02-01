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
    V<V<char>> s(n + 1, V<char>(m + 1, 0));
    V<V<array<int, 2>>> mp(256);
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
            if (isalpha(s[i][j])) {
                mp[s[i][j]].pb({i, j});
            }
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    V<V<int>> d(n + 1, V<int>(m + 1, 1e18));
    V<V<int>> vis(n + 1, V<int>(m + 1, 0));
    d[1][1] = 0;
    vis[1][1] = 1;
    V<char> lett(256, 0);
    queue<array<int, 2>> q;
    q.push({1, 1});
    if (isalpha(s[1][1])) {
        for (auto [x, y] : mp[s[1][1]]) {
            if (x == 1 && y == 1) continue;
            q.push({x, y});
            vis[x][y] = 1;
            d[x][y] = 1;
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#') continue;
            if (d[a][b] > d[x][y] + 1) {
                d[a][b] = d[x][y] + 1;
                vis[a][b] = 1;
                if (isalpha(s[a][b])) {
                    q.push({a, b});
                    if (lett[s[a][b]]) continue; // 这个导致超时了，下次得注意一下（我以为只需要vis就行了）
                    lett[s[a][b]] = 1;
                    for (auto [xx, yy] : mp[s[a][b]]) {
                        if (xx == a && yy == b) continue;
                        if (vis[xx][yy]) continue;
                        if (d[xx][yy] > d[x][y] + 2) {
                            q.push({xx, yy});
                            d[xx][yy] = d[x][y] + 2;
                            vis[xx][yy] = 1;
                        }
                    }
                } else {
                    q.push({a, b});
                }
            }
        }
    }

    if (d[n][m] == 1e18) d[n][m] = -1;

    cout << d[n][m] << endl;
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