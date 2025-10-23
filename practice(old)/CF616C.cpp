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
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    V<int> p(n * m + 1, 0), siz(n * m + 1, 1);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    auto id = [&](int x, int y) { return (x - 1) * m + y; };

    V<V<int>> vis(n + 1, V<int>(m + 1, 0));
    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    auto bfs = [&](int x, int y) {
        queue<PII> q;
        q.push({x, y});
        vis[x][y] = 1;

        while (sz(q)) {
            auto [x, y] = q.front();
            q.pop();

            FOR(i, 0, 3) {
                int a = dx[i] + x, b = dy[i] + y;
                if (a < 1 || b < 1 || a > n || b > m || vis[a][b] || s[a][b] == '*') continue;
                int A = find(id(x, y)), B = find(id(a, b));
                if (A != B) {
                    p[A] = B;
                    siz[B] += siz[A];
                }
                q.push({a, b});
                vis[a][b] = 1;
            }
        }
    };

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '.' && !vis[i][j]) {
                bfs(i, j);
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '*') {
                int tot = 1;
                set<int> val;
                FOR(k, 0, 3) {
                    int a = dx[k] + i, b = dy[k] + j;
                    if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '*') continue;
                    val.insert(find(id(a, b)));
                }
                for (auto x : val) {
                    (tot += siz[x]) %= 10;
                }
                cout << tot;
            } else {
                cout << s[i][j];
            }
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