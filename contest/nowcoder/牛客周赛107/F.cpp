#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
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
    int n, m, q;
    cin >> n >> m >> q;

    V<V<int>> w(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    V<V<int>> d(n + 1, V<int>(m + 1, 1e18));

    priority_queue<TII, V<TII>, greater<TII>> qq;

    FOR(i, 1, m) {
        d[1][i] = w[1][i];
        qq.push({d[1][i], 1, i});
    }

    while (sz(qq)) {
        auto [dd, x, y] = qq.top();
        qq.pop();

        if (dd != d[x][y]) continue;
        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m) continue;
            int ddd = max(dd, w[a][b]);
            if (d[a][b] > ddd) {
                d[a][b] = ddd;
                qq.push({ddd, a, b});
            }
        }
    }

    V<int> ans;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            ans.eb(d[i][j]);
        }
    }

    sort(ALL(ans));

    while (q--) {
        int t;
        cin >> t;
        cout << (upper_bound(ALL(ans), t) - ans.begin()) << endl;
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