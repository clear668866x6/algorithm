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
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    int mod = 998244353;
    int ans = 1;

    auto calc = [&](int x, int m) {
        V<int> c;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                while (x % i == 0) x /= i;
                c.eb(i);
            }
        }
        if (x > 1) {
            c.eb(x);
        }

        int tot = 0;

        FOR(i, 1, (1 << sz(c)) - 1) {
            int cnt = 0, p = 1;
            FOR(j, 0, sz(c) - 1) {
                if (i >> j & 1) {
                    cnt++;
                    p *= c[j];
                }
            }

            if (cnt & 1) {
                tot += m / p;
                tot %= mod;
            } else {
                tot -= m / p;
                tot = (tot % mod + mod) % mod;
            }
        }
        return ((m - tot) % mod + mod) % mod;
    };

    FOR(i, 1, n - 1) {
        if (a[i] % a[i + 1]) {
            cout << 0 << endl;
            RE;
        }
        (ans *= calc(a[i] / a[i + 1], m / a[i + 1])) %= mod;
    }

    cout << ans % mod << endl;
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
