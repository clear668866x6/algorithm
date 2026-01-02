#include <bits/stdc++.h>
#include <iterator>
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
    V<int> d(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        d[b]++;
    }

    V<int> l(n + 1, 0), r(n + 1, 0);

    FOR(i, 1, n) {
        set<int> c;
        for (auto v : g[i]) {
            c.insert(v);
        }
        if (sz(c) == 1) {
            if (*c.begin() < i) {
                r[i] = *c.begin();
            } else {
                l[i] = *c.begin();
            }
        } else if (sz(c) == 2) {
            l[i] = *c.begin(), r[i] = *c.rbegin();
        }
    }

    auto dfs = [&](auto &&dfs, int u) -> void {
        cout << u << ' ';
        if (l[u]) dfs(dfs, l[u]);
        if (r[u]) dfs(dfs, r[u]);
    };
    auto dfs2 = [&](auto &&dfs2, int u) -> void {
        if (l[u]) dfs2(dfs2, l[u]);
        cout << u << ' ';
        if (r[u]) dfs2(dfs2, r[u]);
    };

    auto dfs3 = [&](auto &&dfs3, int u) -> void {
        if (l[u]) dfs3(dfs3, l[u]);
        if (r[u]) dfs3(dfs3, r[u]);
        cout << u << ' ';
    };

    int rt = 1;

    FOR(i, 1, n) {
        if (!d[i]) {
            rt = i;
            break;
        }
    }

    dfs(dfs, rt);
    cout << endl;
    dfs2(dfs2, rt);
    cout << endl;
    dfs3(dfs3, rt);
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