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

    V<V<int>> g(n + 1);

    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    queue<int> q;

    V<int> ans(n + 1, -1), vis(n + 1, 0);

    q.push(1);

    while (sz(q)) {
        int t = q.front();
        q.pop();

        for (auto j : g[t]) {
            if (!vis[j]) {
                ans[j] = t;
                vis[j] = 1;
                q.push(j);
            }
        }
    }

    FOR(i, 2, n) {
        if (ans[i] == -1) {
            No;
            RE;
        }
    }
    Yes;

    FOR(i, 2, n) {
        cout << ans[i] << endl;
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