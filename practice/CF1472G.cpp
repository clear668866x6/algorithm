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

    V<V<int>> g(n + 1), g2(n * 2 + 2);
    V<array<int, 2>> w(m + 1);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        w[i] = {a, b};
    }

    V<int> d(n + 1, 1e18);

    queue<int> q;

    q.push(1);
    d[1] = 0;

    while (sz(q)) {
        int t = q.front();
        q.pop();

        for (auto j : g[t]) {
            if (d[j] > d[t] + 1) {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }

    auto id = [&](int a, int b) { return b * n + a; };

    FOR(i, 1, m) {
        auto [x, y] = w[i];
        if (d[x] >= d[y]) {
            g2[id(y, 0)].eb(id(x, 1));
        } else {
            g2[id(y, 0)].eb(id(x, 0));
            g2[id(y, 1)].eb(id(x, 1));
        }
    }

    V<int> dis(n * 2 + 2, 1e18);
    V<int> vis(n * 2 + 2, 0);
    priority_queue<PII, V<PII>, greater<PII>> qq;

    FOR(i, 1, n) {
        dis[id(i, 0)] = dis[id(i, 1)] = d[i];
        qq.push({d[i], i});
    }

    while (sz(qq)) {
        int ver = qq.top().se;
        qq.pop();

        if (vis[ver]) continue;
        vis[ver] = 1;

        for (auto j : g2[ver]) {
            if (dis[j] > dis[ver]) {
                dis[j] = dis[ver];
                qq.push({dis[j], j});
            }
        }
    }

    FOR(i, 1, n) cout << min(dis[id(i, 0)], dis[id(i, 1)]) << " \n"[i == n];
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
