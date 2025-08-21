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

    if (k & 1) {
        cout << 1 << endl;
        RE;
    }

    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    V<int> siz(n + 1, 0);

    int mod = 1e9 + 7;
    int ans = 0;

    function<void(int, int)> dfs = [&](int u, int fa) {
        siz[u] = 1;
        for (auto j : g[u]) {
            if (j == fa) continue;
            dfs(j, u);
            siz[u] += siz[j];
            (ans += (siz[j]) * (n - siz[j]) % mod) %= mod;
        }
    };

    function<int(int, int)> qmi = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    dfs(1, 0);
    int t = (n - 1) * n % mod;

    cout << (2 * ans + t) % mod * qmi(t, mod - 2) % mod;
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