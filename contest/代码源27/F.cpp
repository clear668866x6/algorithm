#include <algorithm>
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

struct Zhishu {
    static constexpr int N = 1e7 + 10;

    int mu[N], vis[N], primes[N], sum[N];
    int cnt;
    Zhishu() {
        cnt = 0;
        mu[1] = 1;
        int n = 1e7;
        FOR(i, 2, n) {
            if (!vis[i]) primes[cnt++] = i, mu[i] = -1;
            for (int j = 0; i * primes[j] <= n; j++) {
                vis[i * primes[j]] = 1;
                if (i % primes[j] == 0) break;
                mu[i * primes[j]] = -mu[i];
            }
        }
        FOR(i, 1, n) sum[i] = sum[i - 1] + mu[i];
    }

} A;

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int mx = *max_element(ALL(w));

    int ans = 0, mod = 998244353;

    FOR(d, 1, mx + 10) {
        int t = 1;
        FOR(i, 1, n) {
            t = t * (w[i] / d) % mod;
        }
        ans = (ans + (A.mu[d] * t) % mod + mod) % mod;
    }
    cout << (ans % mod + mod) % mod;
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