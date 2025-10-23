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
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;

    V<V<char>> s(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) { cin >> s[i][j]; }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '#') {
                FOR(k, 0, 3) {
                    int a = i + dx[k], b = j + dy[k];
                    if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#')
                        continue;
                    s[a][b] = 'x';
                }
            }
        }
    }

    int ans = 1;

    V<V<int>> vis(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '.' && !vis[i][j]) {
                vis[i][j] = 1;
                queue<PII> q;
                set<PII> p;

                q.push({i, j});
                int cnt = 1;
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();

                    FOR(k, 0, 3) {
                        int a = x + dx[k], b = y + dy[k];
                        if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '#' || vis[a][b])
                            continue;
                        if (s[a][b] == 'x' && !p.count({a, b})) {
                            cnt++;
                            p.insert({a, b});
                            continue;
                        } else if (s[a][b] == 'x') {
                            continue;
                        }
                        vis[a][b] = 1;
                        cnt++;
                        q.push({a, b});
                    }
                }
                ans = max(ans, cnt);
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