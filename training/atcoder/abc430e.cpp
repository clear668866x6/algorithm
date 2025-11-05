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

constexpr int P = 131;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = sz(s);
    t = ' ' + t;
    s += s;
    s = ' ' + s;

    V<int> p(2 * n + 1, 0), hash(2 * n + 1, 0), hash2(n + 1, 0);
    p[0] = 1;
    int mod = 1e9 + 7;

    FOR(i, 1, n * 2) {
        p[i] = p[i - 1] * P % mod;
        hash[i] = ((hash[i - 1] * P % mod) + s[i]) % mod;
    }

    FOR(i, 1, n) {
        hash2[i] = ((hash2[i - 1] * P % mod) + t[i]) % mod;
    }

    auto query = [&](int l, int r) { return (hash[r] - hash[l - 1] * p[r - l + 1] % mod + mod) % mod; };

    int T = hash2[n];

    FOR(i, 1, n) {
        if (query(i, i + n - 1) == T) {
            cout << i - 1 << endl;
            RE;
        }
    }
    cout << -1 << endl;
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
