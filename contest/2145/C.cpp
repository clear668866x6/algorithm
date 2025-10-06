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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    V<int> w(n + 1, 0);
    V<int> pre(n + 1, 0), suf(n + 2, 0);
    V<int> suff(n + 1, 0);

    FOR(i, 1, n) {
        if (s[i] == 'a')
            w[i] = 1;
        else
            w[i] = -1;
    }

    FOR(i, 1, n) {
        pre[i] = pre[i - 1] + w[i];
    }

    map<int, V<int>> mp;
    FORD(i, 1, n) {
        suf[i] = suf[i + 1] + w[i];
    }

    FOR(i, 1, n) {
        mp[suf[i]].eb(i);
    }
    mp[0].eb(n + 1);

    int ans = n;

    FOR(i, 0, n) {
        int t = pre[i];
        auto p = upper_bound(ALL(mp[-t]), i);
        if (p != mp[-t].end()) {
            int idx = *p;
            ans = min(ans, idx - i - 1);
        }
    }

    if (ans == n) ans = -1;
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
