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

    V<V<int>> g(m + 1);

    FOR(i, 1, m) {
        int k, x;
        cin >> k;
        while (k--) {
            cin >> x;
            g[i].eb(x);
        }
    }

    V<int> p(m + 1, 0);

    FOR(i, 1, m) cin >> p[i];
    V<int> vis(n + 1, 0);
    int ans = 0;
    function<void(int)> dfs = [&](int u) {
        if (u == n + 1) {
            bool f = false;
            FOR(i, 1, m) {
                int t = 0;
                for (auto x : g[i]) {
                    (t += vis[x]) %= 2;
                }
                if (t != p[i]) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans++;
            }
            RE;
        }

        vis[u] = 1;
        dfs(u + 1);
        vis[u] = 0;
        dfs(u + 1);
    };

    dfs(1);

    cout << ans;
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