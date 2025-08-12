#include <bits/stdc++.h>
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

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    s = ' ' + s;

    V<int> pre(n + 1, 0), f(n + 2, 0), g(n + 2, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + (s[i] == '1');

    if (!pre[n]) {
        cout << 0 << endl;
        RE;
    }

    FOR(i, 1, n) {
        f[i] = pre[i - 1];
        if (i - k > 0) {
            f[i] = min(f[i], f[i - k] + (pre[i - 1] - pre[i - k - 1]));
        }
        f[i] += (s[i] == '0');
    }

    FORD(i, 1, n) {
        g[i] = pre[n] - pre[i];
        if (i + k <= n) {
            g[i] = min(g[i], g[i + k] + (pre[i + k - 1] - pre[i]));
        }
        g[i] += (s[i] == '0');
    }

    int ans = 1e18;

    FOR(i, 1, n) {
        int t = f[i] + g[i];
        t -= (s[i] == '0');
        ans = min(ans, t);
    }

    cout << ans << endl;
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
