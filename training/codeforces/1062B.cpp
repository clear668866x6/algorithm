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

    int ans = 1;
    int mx = 0, mn = 1e18;

    FOR(i, 2, n) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) n /= i, cnt++;
            mx = max(mx, cnt);
            mn = min(mn, cnt);
            ans *= i;
        }
    }
    if (n > 1) {
        mx = max<int>(mx, 1);
        mn = min<int>(mn, 1);
        ans *= n;
    }

    cout << ans << ' ';

    if (mn == mx) {
        int t = mn, len = 0;
        while (t) len++, t /= 2;
        if (lowbit(mn) == mn) {
            cout << len - 1;
        } else {
            cout << len + 1;
        }
    } else {
        int t = mx, len = 0;
        while (t) len++, t /= 2;
        if (lowbit(mx) == mx) {
            cout << len;
        } else {
            cout << len + 1;
        }
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