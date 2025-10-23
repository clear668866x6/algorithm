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
    int n, k;
    cin >> n >> k;

    map<int, int> mp;

    V<int> w;

    FOR(i, 1, n) {
        int x;
        cin >> x;
        w.eb(x);
        mp[x]++;
    }

    FOR(i, 1, n) {
        int x;
        cin >> x;
    }

    sort(ALL(w));
    w.erase(unique(ALL(w)), w.end());

    int j = 0, t1 = 0;
    V<int> pre(sz(w) + 1, 0), suf(sz(w) + 2, 0);
    FOR(i, 0, sz(w) - 1) {
        t1 += mp[w[i]];
        while (w[i] - w[j] > k) t1 -= mp[w[j]], j++;
        pre[i + 1] = t1;
    }

    j = sz(w) - 1, t1 = 0;

    FORD(i, 0, sz(w) - 1) {
        t1 += mp[w[i]];
        while (w[j] - w[i] > k) t1 -= mp[w[j]], j--;
        suf[i + 1] = t1;
    }

    FOR(i, 1, sz(w)) pre[i] = max(pre[i - 1], pre[i]);
    FORD(i, 1, sz(w)) suf[i] = max(suf[i], suf[i + 1]);

    int ans = 0;

    FOR(i, 0, sz(w)) {
        ans = max(ans, pre[i] + suf[i + 1]);
    }

    if (w[sz(w) - 1] - w[0] <= k * 2) {
        ans = 0;
        FOR(i, 0, sz(w) - 1) ans += mp[w[i]];
    }

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
