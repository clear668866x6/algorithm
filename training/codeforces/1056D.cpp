#include <bits/stdc++.h>
#include <queue>
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
    V<int> fa(n + 1, 0);
    FOR(i, 2, n) {
        int x;
        cin >> x;
        fa[i] = x;
        g[i].eb(x);
        g[x].eb(i);
    }

    if (n == 1) {
        cout << 1;
        RE;
    }

    V<int> siz(n + 1, 0);

    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
            siz[u] += siz[j];
        }
        if (u != 1 && sz(g[u]) == 1) {
            siz[u] = 1;
        }
    };

    dfs(1, 0);

    sort(ALL(siz));

    FOR(i, 1, n) cout << siz[i] << ' ';
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