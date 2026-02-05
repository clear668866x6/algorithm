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
    V<V<int>> w(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            char c;
            cin >> c;
            w[i][j] = c - '0';
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    int c0 = 0, c1 = 0;
    V<V<int>> ans(n + 1, V<int>(m + 1, 0));
    set<array<int, 2>> s;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (w[i][j] == 1)
                c1++;
            else
                c0++;
            int cnt = 0;
            FOR(k, 0, 3) {
                int a = i + dx[k], b = j + dy[k];
                if (a < 1 || b < 1 || a > n || b > m) continue;
                if (!(w[i][j] ^ w[a][b])) {
                    cnt++;
                    ans[i][j] = 1;
                }
            }
            if (!cnt) {
                s.insert({i, j});
            }
        }
    }

    for (auto [x, y] : s) {
        if (w[x][y] == 1) {
            if (c1 - 1 > 0) {
                ans[x][y] = 1;
            }
        } else {
            if (c0 - 1 > 0) {
                ans[x][y] = 1;
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (ans[i][j])
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }
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
