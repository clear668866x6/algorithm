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
    int n, m, k;
    cin >> n >> m >> k;

    V<int> p(n + 1, 0);
    iota(ALL(p), 0ll);

    V g(n + 1, V<PII>());
    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    V<int> w;
    V<array<int, 3>> edg(m + 1);
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
        edg[i] = {a, b, c};
        if (find(a) != find(b)) {
            p[find(a)] = find(b);
        }
    }

    FOR(i, 1, m) {
        if (find(edg[i][0]) == find(1)) {
            w.eb(edg[i][2]);
        }
    }

    sort(ALL(w));
    int tot = 0;

    FOR(i, 0, sz(w) - 1) {
        if (i < k) {
            tot += w[i];
        }
    }

    priority_queue<PII, V<PII>, greater<PII>> q;
    V<int> d(n + 1, 1e18);
    V<int> vis(n + 1, 0);
    d[1] = 0;
    q.push({d[1], 1});

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

    cout << min(tot, d[n]) << endl;
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