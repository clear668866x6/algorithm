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

    int tot = n * n / 2 + 1;

    V<V<int>> w(n + 1, V<int>(n + 1, 0));

    int idx = 1;

    FOR(i, 1, n) {
        w[n / 2 + 1][i] = idx;
        idx += 2;
        tot--;
    }

    FOR(i, 1, n) {
        if (i == n / 2 + 1) continue;
        w[i][n / 2 + 1] = idx;
        idx += 2;
        tot--;
    }

    int x = n / 2, y = n / 2;
    int mid = n / 2 + 1;

    while (tot) {
        if (!x) {
            x = n / 2, y--;
        }
        w[x][y] = idx;
        idx += 2;
        w[2 * mid - x][y] = idx;
        idx += 2;
        w[x][2 * mid - y] = idx;
        idx += 2;
        w[2 * mid - x][2 * mid - y] = idx;
        idx += 2;
        x--;
        tot -= 4;
    }

    idx = 2;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (!w[i][j]) {
                w[i][j] = idx;
                idx += 2;
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cout << w[i][j] << ' ';
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