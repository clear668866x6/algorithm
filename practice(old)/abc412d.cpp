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
    int n, m;
    cin >> n >> m;

    V<V<int>>g (n, V<int> (n));

    FOR (i, 1, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = g[b][a] = 1;
    }

    int ans = 1e18;
    V<int>p (n);
    FOR (i, 0, n - 1)p[i] = i;

    do {
        bool f = false;
        FOR (i, 0, n - 1) {
            if (p[i] == i)f = 1;
            if (p[p[i]] == i)f = 1;
        }
        if (!f) {
            int cur = 0;
            FOR (i, 0, n - 1)cur += g[i][p[i]];
            ans = min (ans, n - cur + m - cur);
        }
    } while (next_permutation (ALL (p)));

    cout << ans << endl;

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