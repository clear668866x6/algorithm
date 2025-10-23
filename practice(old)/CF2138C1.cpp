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
    V<V<int>> g(n + 1);
    FOR(i, 2, n) {
        int x;
        cin >> x;
        g[x].eb(i);
        g[i].eb(x);
    }

    V<int> cnt(n + 1, 0), dep(n + 1, 0);
    int mn = 1e18, s = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        dep[u] = dep[fa] + 1;
        if (sz(g[u]) == 1 && u != 1) {
            mn = min(mn, dep[u]);
        }
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
        }
    };

    dfs(1, 0);

    FOR(i, 1, n) {
        if (dep[i] > mn) {
            s++;
        } else {
            cnt[dep[i]]++;
        }
    }

    V<int> f(k + 1, 0);
    f[0] = 1;

    FOR(i, 1, mn) {
        FORD(j, cnt[i], k) {
            f[j] |= f[j - cnt[i]];
        }
    }

    FORD(i, 0, k) {
        if (f[i]) {
            cout << (mn - (k - i > s)) << endl;
            RE;
        }
    }
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
