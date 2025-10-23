#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve () {
    int n, d;
    cin >> n >> d;

    V<int> w (n);
    map<int, int> mp;
    for (auto& x : w)
        cin >> x, mp[x]++;

    int mx = 1e6;
    if (d == 0) {
        int ans = 0;

        FOR (i, 0, mx) ans += max<int> (0, mp[i] - 1);
        cout << ans << endl;
        RE;
    }

    sort (ALL (w));

    V<V<int>> f (mx + 2, V<int> (2, 0));

    FOR (i, 0, d - 1) {
        f[i][1] = mp[i];
    }
    FOR (i, d, mx) {
        f[i][0] = f[i - d][1];
        f[i][1] = min (f[i - d][0] + mp[i], f[i - d][1] + mp[i]);
    }

    int ans = 0;

    FOR (i, mx - d + 1, mx) ans += min (f[i][0], f[i][1]);

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
