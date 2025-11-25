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
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) w[i] = s[i] - 'A';
    int q;
    cin >> q;

    auto dfs = [&](auto &&dfs, int t, int x) {
        if (!t) return w[x];
        if (x == 1) return ((w[1] + t % 3) % 3);
        if (x & 1) {
            return (dfs(dfs, t - 1, (x + 1) / 2) + 1) % 3;
        } else {
            return (dfs(dfs, t - 1, (x + 1) / 2) + 2) % 3;
        }
    };

    while (q--) {
        int t, x;
        cin >> t >> x;
        cout << char(dfs(dfs, t, x) % 3 + 'A') << endl;
    }
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