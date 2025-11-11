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
    V<array<int, 2>> air(k);
    V<int> ans(n + 1, 0);
    FOR(i, 0, k - 1) cin >> air[i][0];
    FOR(i, 0, k - 1) cin >> air[i][1];

    sort(ALL(air));

    V<int> pre(k + 1, 1e18), suf(k + 2, 1e18);
    FOR(i, 1, k) pre[i] = min(pre[i - 1], (air[i - 1][1] - air[i - 1][0]));
    FORD(i, 1, k) suf[i] = min(suf[i + 1], (air[i - 1][1] + air[i - 1][0]));

    FOR(i, 1, n) {
        int l = 0, r = k;
        auto it = upper_bound(ALL(air), array<int, 2>{i, -1});
        if (it == air.end()) {
            l = it - air.begin();
            r = -1;
        } else if (it == air.begin()) {
            r = it - air.begin() + 1;
            l = -1;
        } else {
            r = it - air.begin() + 1;
            l = r - 1;
        }

        if (l == -1) {
            cout << suf[r] - i << ' ';
        } else if (r == -1) {
            cout << pre[l] + i << ' ';
        } else {
            cout << min(pre[l] + i, suf[r] - i) << ' ';
        }
    }

    cout << endl;
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
