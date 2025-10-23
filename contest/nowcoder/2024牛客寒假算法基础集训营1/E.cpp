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
    int n, m;
    cin >> n >> m;
    V<int>w (n);
    for (auto& x : w)cin >> x;

    V<PII>q (m);
    FOR (i, 0, m - 1) {
        cin >> q[i].fi >> q[i].se;
        q[i].fi--, q[i].se--;
    }

    int ans = n;
    bool f = false;

    function<void (int)>dfs = [&] (int u) {
        if (f)RE;
        if (u == m) {
            V<int>b = w;
            int t = b[0];
            sort (ALL (b), greater<int> ());

            int rk = 1, p = 1;
            if (b[0] == t) {
                ans = 1;
                f = 1;
                RE;
            }
            FOR (i, 1, n - 1) {
                if (b[i] != b[i - 1]) {
                    rk = i + 1;
                }
                if (b[i] == t) {
                    ans = min (ans, rk);
                }
            }
            RE;
        }

        w[q[u].fi] += 3;
        dfs (u + 1);
        w[q[u].fi] -= 3;

        w[q[u].se] += 3;
        dfs (u + 1);
        w[q[u].se] -= 3;

        w[q[u].fi] += 1;
        w[q[u].se] += 1;
        dfs (u + 1);
        w[q[u].fi] -= 1;
        w[q[u].se] -= 1;

        };
    dfs (0);
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