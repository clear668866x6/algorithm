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
    int n, m;
    cin >> n >> m;
    V<int> a(m + 1, 0);
    map<int, V<int>> mp;
    FOR(i, 1, m) {
        cin >> a[i];
        int t;
        cin >> t;
        while (t--) {
            int x;
            cin >> x;
            mp[i].eb(x);
        }
    }

    V<int> f((1 << n), 1e18);
    f[0] = 0;

    FOR(i, 0, (1 << n) - 1) {
        FOR(k, 1, m) {
            int t = 0;
            for (auto x : mp[k]) {
                x--;
                t |= (1 << x);
            }
            f[i | t] = min(f[i | t], f[i] + a[k]);
        }
    }

    if (f[(1 << n) - 1] == 1e18) f[(1 << n) - 1] = -1;

    cout << f[(1 << n) - 1] << endl;
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