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
    reverse(ALL(s)), reverse(ALL(t));

    V<int> ans;

    FOR(i, 0, min(sz(s), sz(t)) - 1) {
        ans.eb((s[i] - '0' + t[i] - '0') % 10);
    }

    FOR(i, min(sz(s), sz(t)), max(sz(s), sz(t)) - 1) {
        if (i < sz(s)) {
            ans.eb(s[i] - '0');

        } else {
            ans.eb(t[i] - '0');
        }
    }
    while (sz(ans) > 1 && ans.back() == 0) ans.pop_back();
    FORD(i, 0, sz(ans) - 1) cout << ans[i];
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