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

void dfs(int u, int sum, int m, V<int> &a, V<int> &b, bool f) {
    if (u >= sz(a)) {
        b.eb(sum % m);
        RE;
    }

    dfs(u + 1, sum, m, a, b, 0);
    dfs(u + 2, (sum + a[u]) % m, m, a, b, 0);
}

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    int mid = n / 2;

    V<int> L, R;
    FOR(i, 1, mid) L.eb(w[i]);
    FOR(i, mid + 1, n) R.eb(w[i]);

    V<int> ls, rs;
    dfs(0, 0, m, L, ls, 1);
    dfs(1, 0, m, R, rs, 0);

    map<int, int> mp;
    for (auto x : rs) mp[x]++;

    int ans = 0;

    for (auto x : ls) {
        int t = (m - x) % m;
        ans += mp[t];
    }

    cout << ans;
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