#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n, m, k;
    cin >> n >> m >> k;

    V<V<char>>w (n + 1, V<char> (m + 1, 0));

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> w[i][j];
        }
    }

    V<V<int>>s (n + 1, V<int> (m + 1, 0));

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (w[i][j] == 'g');
        }
    }

    function<int (int, int, int, int)>calc = [&] (int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        };

    int t = 1e18;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (w[i][j] == '.') {
                int x1 = max<int> (1, i - k + 1), x2 = min (n, i + k - 1);
                int y1 = max<int> (1, j - k + 1), y2 = min (m, j + k - 1);
                t = min (t, calc (x1, y1, x2, y2));
            }
        }
    }

    cout << (s[n][m] - t) << endl;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}