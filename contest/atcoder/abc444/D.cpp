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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];
    sort(ALL(w));
    map<int, int> mp;
    int tot = n;
    FOR(i, 1, n) mp[w[i]]++;
    w.erase(unique(ALL(w)), w.end());
    V<int> ans;
    n = sz(w) - 1;

    FOR(i, 1, n) {
        int x = w[i], y = mp[w[i]];
        int del = w[i] - w[i - 1];
        while (del--) ans.eb(tot);
        tot -= y;
    }
    int add = 0;
    V<int> res;

    for (auto x : ans) {
        int val = (add + x);
        res.eb(val % 10);
        add = val / 10;
    }

    while (add) res.eb(add % 10), add /= 10;
    reverse(ALL(res));
    for (auto x : res) cout << x;
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