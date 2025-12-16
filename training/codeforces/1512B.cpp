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
    V<V<char>> s(n + 1, V<char>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> s[i][j];
        }
    }

    int x1, y1, x2, y2;
    bool f = 0;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (s[i][j] == '*' && !f) {
                x1 = i, y1 = j;
                f = 1;
            } else if (s[i][j] == '*') {
                x2 = i, y2 = j;
            }
        }
    }

    if (x1 == x2) {
        if (x1 + 1 <= n) {
            s[x1 + 1][y1] = s[x2 + 1][y2] = '*';
        } else {
            s[x1 - 1][y1] = s[x2 - 1][y2] = '*';
        }
    } else if (y1 == y2) {
        if (y1 + 1 <= n) {
            s[x1][y1 + 1] = s[x2][y2 + 1] = '*';
        } else {
            s[x1][y1 - 1] = s[x2][y2 - 1] = '*';
        }
    }

    s[x1][y2] = s[x2][y1] = '*';

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cout << s[i][j];
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
