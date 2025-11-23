#include <algorithm>
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
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);

    s = ' ' + s, t = ' ' + t;
    V<int> pre(m + 1, 0), suf(m + 2, 0);
    map<int, V<int>> mp;

    FOR(i, 1, n) {
        mp[s[i]].eb(i);
    }

    int ans = 0;
    int lst = 0;

    FOR(k, 1, m) {
        auto it = upper_bound(ALL(mp[t[k]]), lst);
        int i = *it;
        int len = i - lst - 1;
        ans = max(ans, len);
        lst = i;
        pre[k] = lst;
    }
    ans = max(ans, n - lst);

    lst = n + 1;
    FORD(k, 1, m) {
        auto it = lower_bound(ALL(mp[t[k]]), lst);
        it--;
        int i = *it;
        int len = lst - i - 1;
        ans = max(ans, len);
        lst = i;
        suf[k] = lst;
    }
    ans = max(ans, lst - 1);

    FOR(k, 1, m) {
        ans = max(ans, suf[k] - pre[k - 1] - 1);
    }

    cout << ans << endl;
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