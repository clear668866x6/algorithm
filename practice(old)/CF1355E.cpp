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
    int n, a, r, m;
    cin >> n >> a >> r >> m;
    V<int> h(n + 1);
    FOR(i, 1, n) cin >> h[i];

    m = min(m, a + r);

    auto calc = [&](int x) {
        int c1 = 0, c2 = 0, c3 = 0;
        FOR(i, 1, n) {
            if (h[i] >= x) {
                c2 += h[i] - x;
            } else {
                c1 += x - h[i];
            }
        }

        int tot = min(c1, c2) * m;

        if (c1 > c2) {
            tot += (c1 - c2) * a;
        } else {
            tot += (c2 - c1) * r;
        }

        return tot;
    };

    int L = 0, R = 1e9;
    while (L + 2 != R) {
        int mid1 = (R - L) / 3 + L;
        int mid2 = R - (R - L) / 3;
        if (calc(mid1) > calc(mid2))
            L = mid1;
        else
            R = mid2;
    }

    int ans = 1e18;

    FOR(i, L, R) {
        ans = min(ans, calc(i));
    }

    cout << ans << endl;
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