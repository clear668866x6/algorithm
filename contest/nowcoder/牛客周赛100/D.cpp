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

    V<int>w (n * 2 + 1);

    FOR (i, 1, n * 2)cin >> w[i];

    map<int, int>mpl, mpr;
    V<int>vis (n * 2 + 1, 0);
    FOR (i, 1, n * 2)mpr[w[i]] = i;
    FORD (i, 1, n * 2)mpl[w[i]] = i;

    FOR (i, 1, n * 2)vis[mpr[w[i]]] = 1;

    int ans = 0, res = 0;

    FOR (i, 1, n) {
        ans += (mpr[i] - mpl[i] - 1);
    }

    int idx = 0;

    FOR (i, 1, n * 2) {
        if (vis[i]) {
            idx = i;
            break;
        }
    }

    res = max (res, ans);
    FORD (i, 1, n * 2) {
        if (!vis[i]) {
            int t = ans + (i - idx) * 2;
            res = max (res, t);
        }
    }

    cout << res;


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