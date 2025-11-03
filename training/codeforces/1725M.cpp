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
    V<V<PII>> g(n + 1), g2(n + 1);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b, c);
        g2[b].eb(a, c);
    }

    V<int> d(n + 1, 1e18), gg(n + 1, 1e18);
    auto diji = [&](int u, V<int> &d, V<V<PII>> g) {
        priority_queue<PII, V<PII>, greater<PII>> q;
        V<int> vis(n + 1, 0);
        d[u] = 0;

        q.push({d[u], u});

        while (!q.empty()) {
            int ver = q.top().se;
            q.pop();

            if (vis[ver]) continue;
            vis[ver] = 1;

            for (auto [j, w] : g[ver]) {
                if (d[j] > d[ver] + w) {
                    d[j] = d[ver] + w;
                    q.push({d[j], j});
                }
            }
        }
    };
    diji(1, d, g);
    FOR(i, 1, n) g2[0].eb(i, d[i]);
    diji(0, gg, g2);

    FOR(j, 2, n) {
        if (gg[j] == 1e18) gg[j] = -1;
        cout << gg[j] << ' ';
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