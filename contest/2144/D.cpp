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
    int n, y;
    cin >> n >> y;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];
    int mx = *max_element(ALL(w)) + 1;

    V<int> mp(mx + 1, 0);

    FOR(i, 1, n) mp[w[i]]++;

    V<int> f(mx + 1, 0);

    FOR(i, 1, mx) {
        f[i] = f[i - 1] + mp[i];
    }

    int ans = -1e18;

    FOR(i, 2, mx) {
        int p = 1;
        int tot = 0, div = 0;
        while (i * (p - 1) + 1 <= mx) {
            int l = i * (p - 1) + 1;
            int r = min(mx, i * p);
            int del = f[r] - f[l - 1];
            if (del > 0) {
                tot += p * del;
                div += min(mp[p], del);
            }
            p++;
        }
        ans = max(ans, tot - (n - div) * y);
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
