#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

    struct E {
        int x, y, w;
        bool operator<(const E &t) const {
            return w < t.w;
        }
    };

    V<E> e(m + 1);

    FOR(i, 1, m) {
        cin >> e[i].x >> e[i].y >> e[i].w;
    }

    sort(e.begin() + 1, e.end());

    V<V<PII>> g(n + 1);

    set<int> s;

    FOR(i, 1, min(m, k)) {
        int a = e[i].x, b = e[i].y, c = e[i].w;
        s.insert(a), s.insert(b);
        g[a].eb(b, c);
        g[b].eb(a, c);
    }

    set<int> p = s;

    priority_queue<int, V<int>, greater<int>> qq;

    for (auto x : s) {
        priority_queue<PII, V<PII>, greater<PII>> q;
        q.push({0, x});
        V<int> d(n + 1, 1e18), vis(n + 1, 0);
        d[x] = 0;

        while (sz(q)) {
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
        p.erase(x);
        for (auto x : p) {
            qq.push(d[x]);
        }
    }

    FOR(i, 1, k - 1) qq.pop();

    cout << qq.top() << endl;
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
