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
    int n, k;
    cin >> n >> k;

    V<int> w(k + 1, 0);

    FOR(i, 1, k) cin >> w[i];

    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> d(n + 1, 1e18);
    queue<int> q;

    FOR(i, 1, k) {
        d[w[i]] = 0;
        q.push(w[i]);
    }

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

    bool f = false;
    function<void(int, int, int)> dfs = [&](int u, int fa, int dep) {
        if (f) RE;
        if (sz(g[u]) == 1 && u != 1) {
            f = 1;
            RE;
        }
        for (auto j : g[u]) {
            if (j == fa) continue;
            if (d[j] > dep) {
                dfs(j, u, dep + 1);
            }
        }
    };

    dfs(1, 0, 1);
    if (!f) {
        NO;
    } else {
        YES;
    }
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
