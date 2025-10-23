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

int qmi (int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b % 2 == 1)res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

void solve () {
    int n;
    cin >> n;

    V<int>w (n * 2), cost (n * 2, 0), tag;

    int mod = 1e9 + 7;

    for (auto& x : w)cin >> x;

    sort (RALL (w));
    FOR (i, 0, n * 2 - 1)cost[i] = 100 * qmi (w[i], mod - 2, mod) % mod;

    int ans = 0;

    int j = 0;
    FORD (k, 1, n) {
        int t1 = cost[j++], t2 = cost[j++];
        ans = (ans + (t1 + t2) * k % mod) % mod;
    }

    cout << ans;

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}