#include <bits/stdc++.h>
// using namespace std;

// #define int int64_t
#define endl "\n"

using PII = std::pair<int, int>;
using TII = std::tuple<int, int, int>;
template<class T> using V = std::vector<T>;
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
    std::cin >> n;
    V<i64> w(n + 1, 0);
    FOR(i, 1, n) std::cin >> w[i];

    int mod = 1e9 + 7;

    int len = 0;
    i64 t = *max_element(ALL(w));

    while (t) {
        len++;
        t /= 2;
    }
    V<int> c0(len + 2, 0), c1(len + 2, 0);

    FOR(i, 1, n) {
        FOR(j, 0, len - 1) {
            if (w[i] >> j & 1) {
                c1[j]++;
            } else {
                c0[j]++;
            }
        }
    }

    i64 ans = 0;

    FOR(i, 1, n) {
        i64 tot = 0;
        FOR(j, 0, len - 1) {
            if (w[i] >> j & 1) {
                int t = c0[j];
                tot += (i64)(1ll << j) % mod * t;
                tot %= mod;
            } else {
                int t = c1[j];
                tot += (i64)(1ll << j) % mod * t;
                tot %= mod;
            }
        }
        ans += tot;
        ans %= mod;
    }

    auto qmi = [&](i64 a, i64 b) {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    std::cout << ans * qmi(2, mod - 2) % mod;
}

signed main() {
    int Task = 1;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}