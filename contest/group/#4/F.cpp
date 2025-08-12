#include <bits/stdc++.h>
#include <functional>
using namespace std;

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
    int n;
    cin >> n;

    V<int> a(n + 1, 0), c(n + 1, 0);

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> c[i];

    V<V<int>> g(n + 1);
    V<int> d(n + 1, 0), id(n + 1, 0);

    FOR(i, 1, n) {
        g[i].emplace_back(a[i]);
        d[a[i]]++;
        id[i] = i;
    }

    queue<int> q;

    V<int> ans;

    FOR(i, 1, n) {
        if (!d[i]) {
            q.push(i);
            ans.emplace_back(i);
        }
    }

    V<int> vis(n + 1, 0);

    while (q.size()) {
        int t = q.front();
        q.pop();
        vis[t] = 1;
        for (auto j : g[t]) {
            if (--d[j] == 0) {
                q.push(j);
                ans.emplace_back(j);
            }
        }
    }

    sort(id.begin() + 1, id.end(), [&](int x, int y) { return c[x] < c[y]; });

    FOR(i, 1, n) {
        if (!vis[id[i]]) {
            vis[id[i]] = 1;
            function<void(int)> dfs = [&](int u) {
                if (vis[u])
                    RE;
                vis[u] = 1;
                ans.emplace_back(u);

                for (auto j : g[u]) {
                    dfs(j);
                }
            };
            dfs(a[id[i]]); // 目的：让id[i]是最后便利到的
            ans.emplace_back(id[i]);
        }
    }

    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
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
