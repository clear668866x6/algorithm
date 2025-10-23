#include <bits/stdc++.h>
#include <functional>
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

    int mod = 1e9 + 7;

    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    int t = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        if (sz(g[u]) == 1 && u != 1) t++;

        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    };

    dfs(1, 0);

    auto qmi = [&](int a, int b) {
        if (b < 0) return (int)0;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    if (t > 2) {
        cout << 0 << endl;
    } else if (t == 2) {
        t = 0;
        bool f = false;
        V<int> dep(n + 1, 0);
        function<void(int, int)> dfs2 = [&](int u, int fa) {
            dep[u] = dep[fa] + 1;
            if (!f && sz(g[u]) != 3) {
                t++;
            } else if (sz(g[u]) == 3) {
                f = 1;
                t++;
            }
            for (auto j : g[u]) {
                if (j == fa) continue;
                dfs2(j, u);
            }
        };

        dfs2(1, 0);

        if (sz(g[1]) == 2) t = 1;

        // cout << t << endl;

        int ans = qmi(2, t);

        int t1 = 0, t2 = 0, t3 = 0;
        f = false;

        FOR(i, 2, n) {
            if (!f && sz(g[i]) == 1) {
                t1 = dep[i];
                f = 1;
            } else if (f && sz(g[i]) == 1) {
                t2 = dep[i];
            } else if (sz(g[i]) == 3) {
                t3 = dep[i];
            }
        }

        // FOR(i, 1, n) cout << dep[i] << endl;

        // cout << t1 << ' ' << t2 << ' ' << t3 << endl;

        int siza = t1 - t3, sizb = t2 - t3;

        if (siza == sizb) {
            ans = ans * 2 % mod;
        } else {
            ans = (ans * (qmi(2, abs(siza - sizb) - 1) + qmi(2, abs(siza - sizb)) % mod)) % mod;
        }

        cout << ans << endl;

    } else {
        cout << qmi(2, n) << endl;
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
