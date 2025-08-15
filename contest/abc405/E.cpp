#include <bits/stdc++.h>
#include <cerrno>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

struct E {
    V<int> fac, infac;
    int tot, mod = 998244353;
    E() {}
    E(int x) {
        fac.resize(x + 10);
        infac.resize(x + 10);
        tot = x;
    }

    int qmi(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void init() {
        fac[0] = 1;
        FOR(i, 1, tot) fac[i] = fac[i - 1] * i % mod;

        infac[tot] = qmi(fac[tot], mod - 2);

        FORD(i, 0, tot - 1) {
            infac[i] = infac[i + 1] * (i + 1) % mod;
        }
    }

    int C(int x, int y) {
        if (x < y) return 0;
        return fac[x] * infac[y] % mod * infac[x - y] % mod;
    }


} A(6e6);

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int mod = 998244353;

    A.init();

    int ans = 0;
    FOR(i, 0, c) {
        (ans += A.C(a + b + i, b) * A.C(c + d - i - 1, d - 1) % mod) %= mod;
    }

    cout << ans;
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
