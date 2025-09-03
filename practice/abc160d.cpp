#include <bits/stdc++.h>
#include <queue>
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
    int n, x, y;
    cin >> n >> x >> y;

    V<V<int>> g(n + 1);

    FOR(i, 1, n - 1) {
        int a = i, b = i + 1;
        g[a].eb(b);
        g[b].eb(a);
    }

    g[x].eb(y);
    g[y].eb(x);

    V<V<int>> d(n + 1, V<int>(n + 1, 1e18));

    auto bfs = [&](int x, V<int> &dd) {
        priority_queue<PII, V<PII>, greater<PII>> q;
        q.push({0, x});
        dd[x] = 0;

        V<int> vis(n + 1, 0);

        while (sz(q)) {
            int ver = q.top().se;
            q.pop();

            if (vis[ver]) continue;
            vis[ver] = 1;

            for (auto j : g[ver]) {
                if (dd[j] > dd[ver] + 1) {
                    dd[j] = dd[ver] + 1;
                    q.push({dd[j], j});
                }
            }
        }
    };

    FOR(i, 1, n) {
        bfs(i, d[i]);
    }

    V<int> ans(n + 1, 0);

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            // int t=min(j-i,abs(i-x)+abs(j-y)+1);
            ans[d[i][j]]++;
        }
    }

    FOR(i, 1, n - 1) cout << ans[i] << endl;
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