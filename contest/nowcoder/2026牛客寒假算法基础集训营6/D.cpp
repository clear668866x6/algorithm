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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    V<V<int>> d(n + 1, V<int>(m + 1, 1e18));
    V<V<int>> w(n + 1, V<int>(m + 1, 0));
    int cnt = 0, ans = 0;
    priority_queue<array<int, 3>, V<array<int, 3>>, greater<array<int, 3>>> q;
    FOR(i, 1, a) {
        int x, y;
        cin >> x >> y;
        q.push({0, x, y});
        d[x][y] = 0;
    }

    FOR(i, 1, b) {
        int x, y, t;
        cin >> x >> y >> t;
        w[x][y] = max(w[x][y], t);
    }

    array<int, 4> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [c, x, y] = q.top();
        q.pop();

        FOR(i, 0, 3) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 1 || b < 1 || a > n || b > m) continue;
            int t = max(d[x][y] + 1, w[a][b]);
            if (d[a][b] > t) {
                d[a][b] = t;
                q.push({d[a][b], a, b});
            }
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            ans = max(ans, d[i][j]);
        }
    }

    ans = max(ans, cnt);

    cout << ans;
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