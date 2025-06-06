#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

struct E{
    int mod = 998244353;

    V<int>fac, infac;

    int qmi(int a, int b){
        int res = 1;
        while (b){
            if (b & 1)res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void init(int x){
        fac.resize(x + 10), infac.resize(x + 10);
        fac[0] = 1;
        FOR(i, 1, x){
            fac[i] = fac[i - 1] * i % mod;
        }
        infac[x] = qmi(fac[x], mod - 2) % mod;
        FORD(i, 0, x - 1){
            infac[i] = infac[i + 1] * (i + 1) % mod;
        }
    }

    int A(int x, int y){
        return fac[x] * infac[x - y] % mod;
    }
}A;

void solve() {
    int n;
    cin >> n;
    A.init(1e6);

    if (n == 1){
        cout << 1 << endl;
        RE;
    }

    int ans = 0, mod = 998244353;

    FOR(i, 1, n - 1){
        ans = (ans + i * (i + 1) % mod * (i + 2) % mod * A.qmi(6, mod - 2) % mod) % mod;
    }
    ans = ans * 2 % mod * A.A(n - 2, n - 2) % mod;

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