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

    V<V<PII>> g(n + 1);
    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b) swap(a, b);
        if (a == b) continue;
        if (a == b && c) {
            cout << -1 << endl;
            RE;
        }
        g[a].eb(b, c);
        g[b].eb(a, c);
    }

    V<int> vis(n + 1, 0);

    int ans = 0;
    FORD(i, 0, 32) {
        // 1
        int t = ans | (1ll << i);
        V<int> c1(n + 1, 0), c2(n + 1, 0);
        function<void(int, int, int, int)> dfs2 = [&](int u, int fa, int s, int p) {
            if (vis[u]) {
                RE;
            }
            vis[u] = 1;
            for (auto [j, w] : g[u]) {
                if (j == fa) continue;
                dfs2(j, u, s ^ w, p);
            }
            if (s >> i & 1) {
                if (p) {
                    c1[u]++;
                } else {
                    c2[u]++;
                }
            }
            vis[u] = 0;
        };

        dfs2(1, 0, t, 1);
        dfs2(1, 0, ans, 0);
        int cnt1 = 0, cnt2 = 0;
        for (auto x : c1) {
            if (x) cnt1++;
        }
        for (auto x : c2) {
            if (x) cnt2++;
        }
        if (cnt1 < cnt2) {
            ans |= (1ll << i);
        }
    }

    V<int> res(n + 1, -1);

    function<void(int, int, int)> dfs3 = [&](int u, int fa, int s) {
        if (vis[u]) {
            RE;
        }
        vis[u] = 1;
        if (res[u] == -1) {
            res[u] = s;

        } else {
            if (res[u] != s) {
                cout << -1 << endl;
                exit(0);
            }
        }
        for (auto [j, w] : g[u]) {
            if (j == fa) continue;
            if (res[j] != -1 && (s ^ w) != res[j]) {
                cout << -1 << endl;
                exit(0);
            }
            dfs3(j, u, s ^ w);
        }
        vis[u] = 0;
    };

    dfs3(1, 0, ans);

    FOR(i, 1, n) cout << res[i] << ' ';
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