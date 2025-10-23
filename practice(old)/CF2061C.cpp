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

void solve () {
    int n;
    cin >> n;

    V<int>w (n + 1, 0);

    FOR (i, 1, n)cin >> w[i];

    V<V<int>>f (n + 2, V<int> (2, 0));
    f[0][1] = 1;
    int mod = 998244353;

    FOR (i, 1, n) {
        (f[i][0] += f[i - 1][1]) %= mod;
        if (i >= 2) {
            (f[i][1] += f[i - 1][0] * (w[i - 2] + 1 == w[i])) %= mod;
        }
        (f[i][1] += f[i - 1][1] * (w[i - 1] == w[i])) %= mod;
    }

    int ans = (f[n][0] + f[n][1]) % mod;
    cout << ans << endl;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}