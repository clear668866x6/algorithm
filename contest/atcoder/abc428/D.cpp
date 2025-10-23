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
    int c, d;
    cin >> c >> d;

    V<int> pow10(20, 0);
    pow10[0] = 1;
    FOR(i, 1, 15) pow10[i] = pow10[i - 1] * 10;

    auto getlen = [&](int x) {
        if (!x) return (int)1;
        int len = 0;
        while (x) {
            len++;
            x /= 10;
        }

        return len;
    };

    int L = getlen(c), R = getlen(c + d);
    int ans = 0;

    FOR(t, L, R) {
        int mn = max(c + 1, pow10[t - 1]);
        int mx = min(c + d, pow10[t] - 1);

        if (mn > mx) continue;
        int l = c * pow10[t] + mn;
        int r = c * pow10[t] + mx;

        int low = sqrtl(l);
        while (low * low < l) low++;
        int up = sqrtl(r);
        while (up * up <= r) up++;
        up--;

        if (low <= up) {
            ans += (up - low + 1);
        }
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
