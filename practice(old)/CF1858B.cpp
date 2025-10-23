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
    int n, m, d;
    cin >> n >> m >> d;

    V<int>w;
    w.eb (1);
    FOR (i, 1, m) {
        int x;
        cin >> x;
        w.eb (x);
    }
    w.eb (n + 1);

    int tot = 0;

    FOR (i, 1, w.sz - 1) {
        tot += ((w[i] - w[i - 1] + d - 1) / d);
    }

    int ans = 1e18;

    FOR (i, 1, w.sz - 2) {
        int t = tot - ((w[i] - w[i - 1] + d - 1) / d) - ((w[i + 1] - w[i] + d - 1) / d) + ((w[i + 1] - w[i - 1] + d - 1) / d);
        ans = min (ans, t);
    }

    int res = 0;

    FOR (i, 1, w.sz - 2) {
        int t = tot - ((w[i] - w[i - 1] + d - 1) / d) - ((w[i + 1] - w[i] + d - 1) / d) + ((w[i + 1] - w[i - 1] + d - 1) / d);
        // cout << t << endl;
        if (ans == t)res++;
    }

    cout << ans << ' ' << res << endl;

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