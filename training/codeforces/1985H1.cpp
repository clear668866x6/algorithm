#include <bits/stdc++.h>
#include <functional>
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

    auto get = [&](int x, int y) { return (x - 1) * m + y; };

    V<int> p(n * m + 1, 0), siz(n * m + 1, 1);
    FOR(i, 1, n * m) p[i] = i;

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    V<V<int>> vis(n + 1, V<int>(m + 1, 0));

    auto bfs = [&](int xx, int yy) {
        queue<array<int, 2>> q;
        q.push({xx, yy});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            FOR(i, 0, 3) {
                int a = dx[i] + x, b = dy[i] + y;
                if (a < 1 || b < 1 || a > n || b > m || vis[a][b] || s[a][b] == '.') continue;
                int t1 = get(x, y), t2 = get(a, b);
                t1 = find(t1), t2 = find(t2);
                if (t1 != t2) {
                    p[t1] = t2;
                    siz[t2] += siz[t1];
                }
                vis[a][b] = 1;
                q.push({a, b});
            }
        }
    };

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '#' && !vis[i][j]) {
                vis[i][j] = 1;
                bfs(i, j);
            }
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        int t = 0;
        set<int> st;
        FOR(j, 1, m) {
            if (s[i][j] == '.') {
                t++;
            } else {
                st.insert(find(get(i, j)));
            }
            FOR(k, 0, 3) {
                int a = dx[k] + i, b = dy[k] + j;
                if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '.') continue;
                st.insert(find(get(a, b)));
            }
        }

        for (auto x : st) {
            t += siz[x];
        }

        cerr << "i= " << i << ' ' << t << endl;

        ans = max(ans, t);
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cerr << find(get(i, j)) << ' ';
        }
        cerr << endl;
    }

    FOR(j, 1, m) {
        int t = 0;
        set<int> st;
        FOR(i, 1, n) {
            if (s[i][j] == '.') {
                t++;
            } else {
                st.insert(find(get(i, j)));
            }
            FOR(k, 0, 3) {
                int a = dx[k] + i, b = dy[k] + j;
                if (a < 1 || b < 1 || a > n || b > m || s[a][b] == '.') continue;
                st.insert(find(get(a, b)));
            }
        }

        for (auto x : st) {
            if (j == 6) {
                cerr << "j= " << j << ' ' << t << endl;
            }
            t += siz[x];
        }

        // cerr << "j= " << j << ' ' << t << endl;

        ans = max(ans, t);
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
