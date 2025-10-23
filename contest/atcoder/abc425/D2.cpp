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
    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};

    FOR(t, 1, 100) {
        V<PII> p;
        FOR(i, 1, n) {
            FOR(j, 1, m) {
                if (s[i][j] == '.') {
                    int c = 0;
                    FOR(k, 0, 3) {

                        int a = dx[k] + i, b = dy[k] + j;
                        if (a < 1 || b < 1 || a > n || b > m) continue;
                        if (s[a][b] == '#') {
                            c++;
                        }
                    }
                    if (c == 1) {
                        p.pb({i, j});
                    }
                }
            }
        }
        for (auto [x, y] : p) {
            s[x][y] = '#';
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