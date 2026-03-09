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
    int k, m;
    cin >> k >> m;

    V<int> c(k + 1, 0), l(k + 1, 0);
    FOR(i, 1, k) cin >> c[i] >> l[i];

    int ans = 0;
    int mod = m * 10007 * 9;

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    int s = 0;

    // 错解：比如2233,我这样就是算22x33了。
    //  FOR(i, 1, k) {
    //      int t = c[i] * (qmi(10, l[i]) - 1 + mod) % mod;
    //      ans *= t;
    //      ans %= mod;
    //  }

    FORD(i, 1, k) {
        ans += c[i] * (qmi(10, l[i]) - 1 + mod) * qmi(10, s) % mod;
        ans %= mod;
        s += l[i];
    }

    cout << ans / 9 / m << endl;
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