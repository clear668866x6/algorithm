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

    map<int, V<array<int, 3>>> mp;

    FOR(i, 1, n) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].pb({b, c, i});
    }

    int ans = 0;

    for (auto [x, y] : mp) {
        if (sz(y) == 1)
            ans += y[0][0];
        else {
            int t = 1e18;
            V<int> b, c;
            for (auto [a1, a2, a3] : y) {
                b.eb(a1);
                c.eb(a2);
            }

            int tot = 0;
            FOR(i, 0, sz(c) - 1) {
                tot += c[i];
            }

            FOR(i, 0, sz(c) - 1) {
                t = min(t, tot - c[i] + b[i]);
            }
            ans += t;
        }
    }
    cout << ans;
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