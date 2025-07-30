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
#define sz size()

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    V<V<int>> w(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) { cin >> w[i][j]; }
    }

    V<int> row(n + 1, 0), col(m + 1, 0);

    FOR(i, 1, n) {
        FOR(j, 1, m) { row[i] += w[i][j]; }
    }

    FOR(j, 1, m) {
        FOR(i, 1, n) { col[j] += w[i][j]; }
    }

    int x = 1, y = 1, j = 0;

    while (1) {
        if (s[j] == 'D') {
            w[x][y] = (-row[x]);
            col[y] += (-row[x]);
            x++;
        } else {
            w[x][y] = (-col[y]);
            row[x] += (-col[y]);
            y++;
        }
        j++;
        if (x == n && y == m)
            break;
    }

    w[n][m] = (-row[n]);

    FOR(i, 1, n) {
        FOR(j, 1, m) { cout << w[i][j] << " "; }
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
