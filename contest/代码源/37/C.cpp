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

    V<int> pmn(n + 1, 1e18), pmx(n + 1, 0), smn(n + 2, 1e18), smx(n + 2, 0);

    FOR(i, 1, n) pmn[i] = min(pmn[i - 1], w[i]), pmx[i] = max(pmx[i - 1], w[i]);
    FORD(i, 1, n) smn[i] = min(smn[i + 1], w[i]), smx[i] = max(smx[i + 1], w[i]);

    int ans = 1e18;

    FOR(i, 1, n) {
        int t1 = pmn[i] + i, t2 = pmx[i] + i;
        int t3 = smn[i + 1], t4 = smx[i + 1];
        ans = min(ans, max(t2, t4) - min(t1, t3));
        t1 -= i, t2 -= i;
        ans = min(ans, max(t2, t4) - min(t1, t3));
    }

    cout << ans;
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