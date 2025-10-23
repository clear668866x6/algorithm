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

struct DP {
    static constexpr int N = 10010;

    int f[N][110][2];
    int mod = 1e9 + 7, n, d;
    V<int> c;

    int dfs(int u, int s, bool lim) {
        if (u == n) return s % d == 0;
        if (f[u][s][lim] != -1) return f[u][s][lim];
        int ans = 0;
        FOR(i, 0, (lim ? c[u] : 9)) {
            (ans += dfs(u + 1, (s + i) % d, lim && (i == c[u]))) %= mod;
        }
        return f[u][s][lim] = ans;
    }

    int work(string s, int _d) {
        n = sz(s);
        d = _d;
        memset(f, -1, sizeof f);
        FOR(i, 0, n - 1) {
            c.eb(s[i] - '0');
        }
        return dfs(0, 0, 1);
    }

} A;

void solve() {
    string k;
    int d;
    cin >> k >> d;

    int mod = 1e9 + 7;

    cout << (A.work(k, d) - 1 + mod) % mod;
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