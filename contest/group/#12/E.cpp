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

    V<array<int, 2>> w(k + 1);

    FOR(i, 1, k) cin >> w[i][0];
    FOR(i, 1, k) cin >> w[i][1];

    V<int> ans(n + 1, -1);

    sort(w.begin() + 1, w.end());

    map<int, int> mp, mp2;

    FOR(i, 1, k) mp[w[i][0]]++;

    V<int> pre(n + 1, 1e18), suf(n + 2, 1e18);
    int j = 1;

    FOR(i, 1, n) {
        if (mp[i]) {
            pre[i] = min(pre[i - 1], w[j][1] - w[j][0]);
            j++;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    j = k;
    FORD(i, 1, n) {
        if (mp[i]) {
            suf[i] = min(suf[i + 1], w[j][1] + w[j][0]);
            j--;
        } else {
            suf[i] = suf[i + 1];
        }
    }

    FOR(i, 1, n) {
        ans[i] = min(pre[i] + i, suf[i] - i);
    }

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
