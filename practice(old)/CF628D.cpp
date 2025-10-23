#include <bits/stdc++.h>
#include <cstring>
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

int mod = 1e9 + 7;
struct Shuweidp {
    static constexpr int N = 2010;
    int f[N][N];
    string num;
    int d, m;

    int dfs(int u, int s, bool lim) {
        if (u == sz(num)) return !s;
        if (!lim && ~f[u][s]) return f[u][s];
        int res = 0;
        FOR(i, 0, (lim ? num[u] - '0' : 9)) {
            if (((u & 1) && i != d) || (!(u & 1) && i == d)) continue;
            res = (res + dfs(u + 1, (s * 10 + i) % m, lim && i == num[u] - '0')) % mod;
        }
        if (!lim) f[u][s] = res;
        return res;
    }

    int work(string x, int t, int _m) {
        num = x;
        d = t;
        m = _m;

        memset(f, -1, sizeof f);

        return dfs(0, 0, 1);
    }

} A;

void solve() {
    int m, d;
    string a, b;
    cin >> m >> d >> a >> b;

    int mx = max(sz(a), sz(b));

    auto check = [&](string s) {
        int res = 0;
        FOR(i, 0, sz(s) - 1) {
            res = (res * 10 + s[i] - '0') % m;
            if (((i & 1) && (s[i] - '0' != d)) || (!(i & 1) && (s[i] - '0' == d))) return int(0);
        }
        return int(res == 0);
    };

    cout << ((A.work(b, d, m) - A.work(a, d, m) + check(a) + mod) % mod);
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