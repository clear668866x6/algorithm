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
    V<V<int>> g(n + 1);
    V<int> c(n + 1, 0);
    V<int> fa(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    FOR(i, 1, n) cin >> c[i];

    V<int> dep(n + 1, 0);

    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    int mx = *max_element(ALL(dep));

    V<int> p;
    map<int, V<int>> mp;

    FOR(i, 1, n) {
        p.eb(dep[c[i]]);
        mp[dep[c[i]]].eb(c[i]);
    }

    p.erase(unique(ALL(p)), p.end());

    if (sz(p) != mx + 1) {
        No;
    } else {
        FOR(i, 1, sz(p) - 1) {
            if (p[i] != p[i - 1] + 1) {
                No;
                RE;
            }
        }

        FOR(i, 1, n) {
            for (auto v : g[i]) {
                if (dep[v] > dep[i]) {
                    fa[v] = i;
                }
            }
        }

        FOR(i, 2, mx) {
            V<int> cur = mp[i], lst = mp[i - 1];
            int p = sz(cur);
            V<int> cc, cc2;
            FOR(j, 0, p - 1) {
                cc.eb(fa[cur[j]]);
            }
            p = sz(lst);
            FOR(j, 0, p - 1) {
                if (sz(g[lst[j]]) > 1) {
                    cc2.eb(lst[j]);
                }
            }

            cc.erase(unique(ALL(cc)), cc.end());

            if (cc != cc2) {
                No;
                RE;
            }
        }

        Yes;
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