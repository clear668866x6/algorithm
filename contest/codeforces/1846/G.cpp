#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int t = 0;
    for (auto x : s) {
        t = t * 2 + (x - '0');
    }

    V<array<int, 3>> p(m);
    V<V<PII>> g(1 << n);

    FOR(i, 0, m - 1) {
        int d;
        string a, b;
        cin >> d >> a >> b;
        int t1 = 0, t2 = 0;
        for (auto& x : a) {
            if (x == '1')
                x = 0;
            else
                x = 1;
            t1 = t1 * 2 + x;
        }
        FOR(i, 0, n - 1) t2 = t2 * 2 + (b[i] - '0');

        p[i] = {t1, t2, d};
    }

    FOR(i, 0, (1 << n) - 1) {
        FOR(j, 0, m - 1) { g[i].emplace_back(i & p[j][0] | p[j][1], p[j][2]); }
    }

    priority_queue<PII, V<PII>, greater<PII>> q;

    V<int> vis(1 << n, 0);
    V<int> d(1 << n, 1e18);
    d[t] = 0;
    q.push({0, t});

    while (q.size()) {
        int ver = q.top().se;
        q.pop();

        if (vis[ver])
            continue;
        vis[ver] = 1;

        for (auto [j, w] : g[ver]) {
            if (d[j] > d[ver] + w) {
                d[j] = d[ver] + w;
                q.push({d[j], j});
            }
        }
    }

    if (d[0] == 1e18)
        d[0] = -1;

    cout << d[0] << endl;
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
