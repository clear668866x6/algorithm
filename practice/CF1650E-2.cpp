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
    int n, d;
    cin >> n >> d;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int pos = 1;

    FOR(i, 1, n) {
        if (w[i] - w[i - 1] - 1 < w[pos] - w[pos - 1] - 1) pos = i;
    }

    auto calc = [&](int x) {
        int lst = 0, mn = 1e18, mx = 0;
        FOR(i, 1, n) {
            if (i == x) continue;
            mn = min(mn, w[i] - w[lst] - 1);
            mx = max(mx, w[i] - w[lst] - 1);
            lst = i;
        }
        return min(mn, max((mx - 1) / 2, d - w[lst] - 1));
    };

    int ans = 0;
    ans = calc(pos);
    if (pos > 1) ans = max(ans, calc(pos - 1));

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
