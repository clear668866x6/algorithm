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

void solve() {
    int n, k;
    cin >> n >> k;

    if (!k) {
        FOR(i, 1, n) cout << i << " \n"[i == n];
        RE;
    }

    V<int> c;
    V<int> ans;
    V<int> cob(n + 2, 0);

    FOR(i, 0, n) cob[i] = i * (i - 1) / 2;

    int tot = n * (n - 1) / 2;
    int del = tot - k;

    V<V<int>> f(n + 1, V<int>(tot + 1, -1)), c2(n + 1, V<int>(tot + 1, -1));

    function<int(int, int)> dfs = [&](int u, int s) {
        if (s < 0) return (int)0;
        if (u == 0) return (int)(s == 0);
        if (f[u][s] != -1) return f[u][s];
        f[u][s] = 0;
        FOR(L, 1, u) {
            int c = cob[L];
            if (c > s) continue;
            if (dfs(u - L, s - c)) {
                c2[u][s] = L;
                f[u][s] = 1;
                return f[u][s];
            }
        }
        return (int)0;
    };

    if (!dfs(n, del)) {
        cout << 0 << endl;
        RE;
    }

    int rem = n, cur = del;
    while (rem > 0) {
        int L = c2[rem][cur];
        if (L == -1) break;
        c.eb(L);
        rem -= L;
        cur -= cob[L];
    }

    cur = n;

    for (auto x : c) {
        int st = cur - x + 1;
        FOR(i, st, cur) ans.eb(i);
        cur -= x;
    }

    FOR(i, 0, n - 1) cout << ans[i] << " \n"[i == n - 1];
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
