
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
    int l, r;
    cin >> l >> r;

    V<int> ans(r - l + 3, 0);

    function<void(int, int, int)> calc = [&](int l, int r, int st) {
        if (l > r) RE;
        if (l == r) {
            ans[st] = l;
            RE;
        }

        if (bit_width(unsigned(l)) == bit_width(unsigned(r))) {
            int w = bit_width(unsigned(l)) - 1;
            calc(l - (1 << w), r - (1 << w), st);
            FOR(i, l, r) ans[i + st - l] |= 1 << w;
            RE;
        }

        int w = bit_width(unsigned(r)) - 1;

        int mid = (1 << w);

        if (r - mid + 1 >= mid - l) {
            FOR(i, l, mid - 1) {
                int x = i, y = mid * 2 - x - 1;
                ans[x + st - l] = y;
                ans[y + st - l] = x;
            }
            calc(2 * mid - l, r, st + 2 * (mid - l));
        } else {
            FOR(i, mid, r) {
                int x = i, y = mid * 2 - x - 1;
                ans[x + st - l] = y;
                ans[y + st - l] = x;
            }
            calc(l, mid - (r - mid + 1) - 1, st);
        }
    };

    calc(l, r, 0);

    int tot = 0;

    FOR(i, l, r) tot += (i | ans[i - l]);

    cout << tot << endl;
    FOR(i, l, r) cout << ans[i - l] << " \n"[i == r];
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
