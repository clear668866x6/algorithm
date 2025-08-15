#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 1, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + w[i];

    map<int, V<array<int, 2>>> mp;

    FOR(l, 1, n) {
        FOR(r, l, n) {
            int t = pre[r] - pre[l - 1];
            mp[t].pb({l, r});
        }
    }

    for (auto &[x, y] : mp) {
        V<array<int, 2>> t;
        int lst = -1;
        FORD(j, 0, sz(y) - 1) {
            if (lst == -1 || lst > y[j][1]) {
                t.pb(y[j]);
                lst = y[j][0];
            }
        }
        y = t;
    }

    V<array<int, 2>> ans;
    int cnt = 0;

    for (auto &[x, y] : mp) {
        if (sz(y) >= cnt) {
            cnt = sz(y);
            ans = y;
        }
    }

    cout << cnt << endl;

    FOR(i, 0, sz(ans) - 1) cout << ans[i][0] << ' ' << ans[i][1] << endl;
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