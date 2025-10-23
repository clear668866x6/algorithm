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
    map<char, V<int>> mp;
    int n = sz(s), m = sz(t);
    s = ' ' + s, t = ' ' + t;

    FOR(i, 1, n)
    mp[s[i]].eb(i);
    FOR(i, 1, m) {
        if (!sz(mp[t[i]])) {
            cout << -1 << endl;
            RE;
        }
    }

    int mx = 0, ans = 0;
    FOR(i, 1, m) {
        char p = t[i];
        auto t = upper_bound(ALL(mp[p]), mx);
        if (t == mp[p].end()) {
            ans++, mx = 0;
            mx = mp[p][0];
        } else {
            mx = *t;
        }
    }
    if (mx) ans++;
    cout << ans << endl;
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
