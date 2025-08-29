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
    int n;
    cin >> n;
    string r, c;
    cin >> r >> c;

    V<V<char>> s(n + 2, V<char>(n + 2, '.'));

    auto check = [&]() {
        string a, b;
        FOR(i, 1, n) {
            bool f = false;
            FOR(j, 1, n) {
                if (s[i][j] != '.' && !f) {
                    f = 1;
                    a += s[i][j];
                }
            }
        }

        FOR(j, 1, n) {
            bool f = false;
            FOR(i, 1, n) {
                if (s[i][j] != '.' && !f) {
                    f = 1;
                    b += s[i][j];
                }
            }
        }

        int c1 = 0, c2 = 0, c3 = 0;

        FOR(i, 1, n) {
            c1 = c2 = c3 = 0;
            FOR(j, 1, n) {
                c1 += (s[i][j] == 'A');
                c2 += (s[i][j] == 'B');
                c3 += (s[i][j] == 'C');
            }
            if (c1 != 1 || c2 != 1 || c3 != 1) return 0;
        }

        FOR(j, 1, n) {
            c1 = c2 = c3 = 0;
            FOR(i, 1, n) {
                c1 += (s[i][j] == 'A');
                c2 += (s[i][j] == 'B');
                c3 += (s[i][j] == 'C');
            }
            if (c1 != 1 || c2 != 1 || c3 != 1) return 0;
        }

        if (a == r && b == c) return 1;
        return 0;
    };

    V<V<int>> row(n + 1, V<int>(256, 0)), col(n + 1, V<int>(256, 0));
    map<int, int> c1, c2;
    function<void(int, int)> dfs = [&](int x, int y) {
        if (x == n + 1 && y == 1) {
            if (check()) {
                Yes;
                FOR(i, 1, n) {
                    FOR(j, 1, n) {
                        cout << s[i][j];
                    }
                    cout << endl;
                }
                exit(0);
            }
            RE;
        }
        if (c1[x] > 3 || c2[y] > 3) RE;
        if (n - y + 1 < 3 - c1[x] || n - x + 1 < 3 - c2[y]) RE;

        if (y == n) {
            for (auto cc : {'A', 'B', 'C'}) {
                if (!row[x][cc] && !col[y][cc]) {
                    if (!c1[x] && cc != r[x - 1]) continue;
                    if (!c2[y] && cc != c[y - 1]) continue;
                    row[x][cc]++;
                    col[y][cc]++;
                    s[x][y] = cc;
                    c1[x]++;
                    c2[y]++;
                    dfs(x + 1, 1);
                    c1[x]--;
                    c2[y]--;
                    row[x][cc]--;
                    col[y][cc]--;
                    s[x][y] = '.';
                }
            }
            dfs(x + 1, 1);
        } else {
            for (auto cc : {'A', 'B', 'C'}) {
                if (!row[x][cc] && !col[y][cc]) {
                    if (!c1[x] && cc != r[x - 1]) continue;
                    if (!c2[y] && cc != c[y - 1]) continue;
                    row[x][cc]++;
                    col[y][cc]++;
                    s[x][y] = cc;
                    c1[x]++;
                    c2[y]++;
                    dfs(x, y + 1);
                    c1[x]--;
                    c2[y]--;
                    row[x][cc]--;
                    col[y][cc]--;
                    s[x][y] = '.';
                }
            }
            dfs(x, y + 1);
        }
    };
    dfs(1, 1);

    No;
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