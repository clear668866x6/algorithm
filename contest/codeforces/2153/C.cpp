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
    map<int, int> mp;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;

    int ans = 0, tot = 0;
    V<int> c;
    int mx = 0;
    for (auto [x, y] : mp) {
        if (y & 1) {
            int p = y / 2 * 2;
            if (p) {
                mx = max(mx, x);
            }
            tot += p * x;
            c.eb(x);
        } else {
            tot += y * x;
            mx = max(mx, x);
        }
    }

    if (!sz(c)) {
        cout << ans << endl;
    } else {
        if (sz(c) == 1) {
            if (c[0] > mx && tot > c[0]) {
                ans = max(ans, tot + c[0]);
            } else if (c[0] <= mx) {
                ans = max(ans, tot + c[0]);
            }
        } else {
            FOR(i, 1, sz(c) - 1) {
                if (c[i] > mx && tot + c[i - 1] > c[i]) {
                    ans = max(ans, tot + c[i - 1] + c[i]);
                } else if (c[i] <= mx) {
                    ans = max(ans, tot + c[i] + c[i - 1]);
                }
            }
        }
        cout << ans << endl;
    }
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
