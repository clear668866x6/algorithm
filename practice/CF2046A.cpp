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
    V<PII>w (n);
    FOR (i, 0, n - 1)cin >> w[i].fi;
    FOR (i, 0, n - 1)cin >> w[i].se;

    int ans = -1e18;

    FOR (i, 0, n - 1) {
        int p = w[0].fi + w[0].se;
        int a = w[0].fi, b = w[0].se;
        w.erase (w.begin ());
        V<int>f (n + 2, -1e18);
        f[0] = 0;
        FOR (j, 1, n - 1) {
            f[j] = max (f[j - 1] + w[j - 1].fi, f[j - 1] + w[j - 1].se);
        }
        w.push_back ({ a,b });
        ans = max (ans, f[n - 1] + p);
    }

    cout << ans << endl;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}