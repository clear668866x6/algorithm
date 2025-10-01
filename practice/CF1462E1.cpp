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
    V<int> w(n + 1, 0), mp(n + 10, 0);
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;

    ranges::sort(w);
    w.erase(unique(ALL(w)), w.end());

    n = sz(w) - 1;

    int ans = 0;

    FOR(i, 1, n) {
        int t1 = mp[w[i]], t2 = mp[w[i] + 1], t3 = mp[w[i] + 2];
        int c1 = (t1 * (t1 - 1) * (t1 - 2) / 6);
        int c2 = (t1 * (t1 - 1) / 2 * t2);
        int c3 = (t1 * (t1 - 1) / 2 * t3);
        int c4 = t1 * (t2 - 1) * (t2) / 2;
        int c5 = t1 * t2 * t3;
        int c6 = t1 * (t3 - 1) * t3 / 2;
        ans += (c1 + c2 + c3 + c4 + c5 + c6);
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
