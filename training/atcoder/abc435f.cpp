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
    V<int> p(n + 1, 0);
    FOR(i, 1, n) cin >> p[i];

    V<int> l(n + 1, 0), r(n + 1, 0);
    V<int> stk;
    int rt = 0;

    FOR(i, 1, n) {
        int lst = 0;
        while (!stk.empty() && p[stk.back()] < p[i]) {
            lst = stk.back();
            stk.pop_back();
        }

        if (!stk.empty())
            r[stk.back()] = i;
        else
            rt = i;

        l[i] = lst;
        stk.pb(i);
    }
    V<int> f(n + 1, 0);

    auto dfs = [&](auto &&dfs, int u) -> void {
        if (l[u]) dfs(dfs, l[u]);
        if (r[u]) dfs(dfs, r[u]);

        if (l[u]) {
            f[u] = max(f[u], f[l[u]] + abs(l[u] - u));
        }
        if (r[u]) {
            f[u] = max(f[u], f[r[u]] + abs(r[u] - u));
        }
    };
    dfs(dfs, rt);

    cout << f[rt];
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