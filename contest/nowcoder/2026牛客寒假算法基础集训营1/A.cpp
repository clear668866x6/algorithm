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

constexpr int mod = 998244353;
V<V<int>> mp{{1, 2, 3, 5, 6, 7}, {3, 6},    {1, 3, 4, 5, 7},       {1, 3, 4, 6, 7},   {2, 3, 4, 6}, {1, 2, 4, 6, 7},
             {1, 2, 4, 5, 6, 7}, {1, 3, 6}, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 6, 7}};

void solve() {
    int c;
    cin >> c;
    int n = 7;
    V<int> p(n + 1, 0);
    FOR(i, 1, n) cin >> p[i];

    int ans = 0;

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    int inv = qmi(100, mod - 2);

    FOR(a, 0, c) {
        int b = c - a;
        string sa = to_string(a), sb = to_string(b);
        reverse(ALL(sa)), reverse(ALL(sb));
        int t1 = 4 - sz(sa), t2 = 4 - sz(sb);
        while (t1--) sa += '0';
        while (t2--) sb += '0';
        reverse(ALL(sa)), reverse(ALL(sb));
        int tot = 1;
        FOR(i, 0, sz(sa) - 1) {
            V<int> vis(n + 2, 0);
            for (auto v : mp[sa[i] - '0']) {
                tot *= p[v] * inv % mod;
                tot %= mod;
                vis[v] = 1;
            }

            FOR(v, 1, 7) {
                if (!vis[v]) {
                    tot *= (100 - p[v]) * inv % mod;
                    tot %= mod;
                }
            }
        }

        FOR(i, 0, sz(sb) - 1) {
            V<int> vis(n + 2, 0);
            for (auto v : mp[sb[i] - '0']) {
                tot *= p[v] * inv % mod;
                tot %= mod;
                vis[v] = 1;
            }
            FOR(v, 1, 7) {
                if (!vis[v]) {
                    tot *= (100 - p[v]) * inv % mod;
                    tot %= mod;
                }
            }
        }
        ans += tot;
        ans %= mod;
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
