#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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

    int tot = accumulate(ALL(w), 0ll);
    int mx = *max_element(ALL(w)), mn = *min_element(w.begin() + 1, w.end());
    int idxmx = 0, idxmn = 0;

    FOR(i, 1, n) {
        if (mx == w[i]) idxmx = i;
        if (mn == w[i]) idxmn = i;
    }

    auto calc = [&](int base, int idx) {
        int ans = 0;
        FOR(i, 1, n) {
            if (i == idx) continue;
            if (w[i] > base) ans += w[i] - base;
        }
        return ans;
    };

    if (tot % n == 0) {
        cout << calc(tot / n, -1);
    } else {
        int k = (tot - mx) % (n - 1);
        int ans = calc((tot - mx) / (n - 1), idxmx);
        ans = min(ans, calc(((tot - mx) / (n - 1) + 1), idxmx) + n - 1 - k);
        k = (tot - mn) % (n - 1);
        ans = min(ans, calc((tot - mn) / (n - 1), idxmn));
        ans = min(ans, calc(((tot - mn) / (n - 1) + 1), idxmn) + n - 1 - k);
        cout << ans << endl;
    }
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