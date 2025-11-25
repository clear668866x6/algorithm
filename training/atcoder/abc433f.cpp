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
    static constexpr int N = 2e6 + 10;
    int fac[N], infac[N];

    int qmi(int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

    void init() {
        int n = N - 10;
        fac[0] = 1;
        FOR(i, 1, n) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);
        FORD(i, 0, n - 1) infac[i] = infac[i + 1] * (i + 1) % mod;
    }

    int C(int x, int y) {
        return fac[x] * infac[y] % mod * infac[x - y] % mod;
    }

} A;

void solve() {
    string s;
    cin >> s;
    A.init();
    int n = sz(s);
    s = ' ' + s;

    V<V<int>> pre(n + 1, V<int>(12, 0)), suf(n + 2, V<int>(12, 0));

    FOR(i, 1, n) {
        FOR(j, 0, 9) {
            pre[i][j] = pre[i - 1][j] + (s[i] - '0' == j);
        }
    }

    FORD(i, 1, n) {
        FOR(j, 0, 9) {
            suf[i][j] = suf[i + 1][j] + (s[i] - '0' == j);
        }
    }
    int ans = 0;

    FOR(i, 1, n) {
        int t = s[i] - '0';
        int l = pre[i - 1][t], r = suf[i + 1][t + 1];
        ans += A.C(l + r, r - 1);
        ans %= mod;
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