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

    V<V<int>> w(n + 1, V<int>(n));
    map<int, int> mp;
    FOR(i, 1, n) {
        FOR(j, 1, n - 1) cin >> w[i][j];

        mp[w[i][n - 1]]++;
    }

    int t = 0, t2 = 0;

    for (auto [x, y] : mp) {
        if (y != n - 1)
            t = x;
        else
            t2 = x;
    }

    V<int> ans;

    FOR(i, 1, n) {
        if (w[i][n - 1] == t) {
            ans = w[i];
            break;
        }
    }

    ans.eb(t2);

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
