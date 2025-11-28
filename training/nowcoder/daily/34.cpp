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
    int n, m;
    cin >> n >> m;
    V<array<int, 2>> w(m + 1), seg;

    FOR(i, 1, m) cin >> w[i][0] >> w[i][1];

    sort(ALL(w));

    int l = w[1][0], r = w[1][1];

    FOR(i, 2, m) {
        if (w[i][0] > r) {
            seg.pb({l, r});
            l = w[i][0], r = w[i][1];
        } else {
            r = max(r, w[i][1]);
        }
    }

    seg.pb({l, r});

    int ans = seg[0][0];

    FOR(i, 1, sz(seg) - 1) {
        ans = max(ans, seg[i][0] - seg[i - 1][1]);
    }
    ans = max(ans, n - seg.back()[1]);

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