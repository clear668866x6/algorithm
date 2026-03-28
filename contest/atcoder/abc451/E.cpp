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
    V<V<int>> w(n + 1, V<int>(n + 1, 0));
    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            cin >> w[i][j];
        }
    }

    V<array<int, 3>> d;

    FOR(i, 1, n) {
        FOR(j, i + 1, n) {
            d.pb({w[i][j], i, j});
        }
    }

    sort(ALL(d));

    V<int> p(n + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    V<V<array<int, 2>>> g(n + 1);

    FOR(i, 0, sz(d) - 1) {
        auto [c, a, b] = d[i];
        int da = find(a), db = find(b);
        if (da != db) {
            p[da] = db;
            g[a].pb({b, c});
            g[b].pb({a, c});
        }
    }

    auto diji = [&](int x, V<int> &d) {
        priority_queue<array<int, 2>, V<array<int, 2>>, greater<array<int, 2>>> q;
        V<int> vis(n + 1, 0);
        d[x] = 0;
        q.push({d[x], x});

        while (!q.empty()) {
            auto [dd, ver] = q.top();
            q.pop();

            if (vis[ver]) continue;
            vis[ver] = 1;

            for (auto [v, val] : g[ver]) {
                if (d[v] > d[ver] + val) {
                    d[v] = d[ver] + val;
                    q.push({d[v], v});
                }
            }
        }
    };

    FOR(i, 1, n) {
        V<int> dd(n + 1, 1e18);
        diji(i, dd);

        FOR(j, i + 1, n) {
            if (w[i][j] != dd[j]) {
                No;
                RE;
            }
        }
    }
    Yes;
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