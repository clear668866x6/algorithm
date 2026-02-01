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
    int n, c;
    cin >> n >> c;
    V<V<char>> s(n + 1, V<char>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> s[i][j];
        }
    }

    V<V<int>> vis(n + 1, V<int>(n + 1, 0));
    V<int> d(n + 1, 0);

    FOR(j, 1, n) {
        FORD(i, 1, n) {
            if (s[i][j] == '.') {
                d[j]++;
            } else {
                break;
            }
        }
    }

    auto bfs = [&]() {
        queue<array<int, 2>> q;
        q.push({n, c});
        array<int, 3> dx = {-1, -1, -1}, dy = {1, 0, -1};

        vis[n][c] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            FOR(i, 0, 2) {
                int a = dx[i] + x, b = dy[i] + y;
                if (a < 1 || b < 1 || a > n || b > n || vis[a][b]) continue;
                if (s[a][b] == '#') {
                    int t = n - a;
                    if (t == d[b]) {
                        FOR(i, 1, n) {
                            s[i][b] = '.';
                        }
                    } else {
                        continue;
                    }
                }
                q.push({a, b});
                vis[a][b] = 1;
            }
        }
    };

    bfs();

    FOR(i, 1, n) {
        if (vis[1][i])
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
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
