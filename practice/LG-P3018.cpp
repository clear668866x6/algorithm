#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n;
    cin >> n;
    V<V<int>>g (n + 1);
    V<int>c (n + 1, 0), t (n + 1, 0);
    int rt = 0;
    FOR (i, 1, n) {
        int x;
        cin >> x >> c[i] >> t[i];
        if (x == -1)rt = i;
        else {
            g[i].eb (x);
            g[x].eb (i);
        }
    }

    int ans = 0;
    V<int>siz (n + 1, 0);

    function<void (int, int)>dfs = [&] (int u, int fa) {
        int tot = 0, mn = 1e18;
        for (auto j : g[u]) {
            if (j == fa)continue;
            dfs (j, u);
            siz[u] += siz[j];
            t[u] = min (t[u], t[j]);
        }
        if (siz[u] < c[u]) {
            ans += (c[u] - siz[u]) * t[u];
            siz[u] = c[u];
        }
        };

    dfs (rt, 0);

    cout << ans;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}