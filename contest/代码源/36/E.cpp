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

constexpr int mod = 998244353;

struct Comb {
    static constexpr int N = 1e6 + 10;
    int fac[N], infac[N];
    int n;

    int qmi(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    }

    void init() {
        n = N - 10;
        fac[0] = 1;
        FOR(i, 1, n) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);
        FORD(i, 0, n - 1) {
            infac[i] = infac[i + 1] * (i + 1) % mod;
        }
    }

    int C(int x, int y) {
        if (x < y || x <= 0) return 0;
        return fac[x] * infac[y] % mod * infac[x - y] % mod;
    }

} A;

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    A.init();

    V<int> f(1e6 + 10, 0);
    int n = 1e6;
    f[0] = 1;

    FOR(i, 2, n) {
        FOR(j, 2, 5) {
            if (i - j >= 0) {
                f[i] += A.C(i - 1, j - 1) * j * f[i - j] % mod;
                f[i] %= mod;
            }
        }
    }

    auto solve = [&]() {
        int n;
        cin >> n;
        cout << f[n] << endl;
    };

    while (Task--) {
        solve();
    }

    return 0;
}
