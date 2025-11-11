#include <algorithm>
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
    V<V<PII>> g(n + 1);
    int tot = 0;
    FOR(i, 2, n) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b, c);
        g[b].eb(a, c);
        tot += 2 * c;
    }

    V<int> d(n + 1, 0);
    function<void(int)> bfs = [&](int f) {
        queue<int> q;
        q.push(f);
        V<int> vis(n + 1, 0);
        vis[f] = 1;
        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (auto [j, w] : g[t]) {
                if (!vis[j]) {
                    vis[j] = 1;
                    d[j] = d[t] + w;
                    q.push(j);
                }
            }
        }
    };

    bfs(1);
    int idx = 1;
    FOR(i, 1, n) {
        if (d[i] > d[idx]) idx = i;
    }
    d[idx] = 0;
    bfs(idx);

    cout << tot - *max_element(ALL(d)) << endl;
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