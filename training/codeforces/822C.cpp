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
    int n, x;
    cin >> n >> x;
    V<array<int, 3>> w(n + 1, {0, 0, 0});
    map<int, V<int>> mp;
    map<int, PII> mp2;
    FOR(i, 1, n) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = {a, b, c};
        mp[b - a + 1].eb(i);
    }

    for (auto [x, y] : mp) {
        int t = 1e18, c = 0;
        for (auto z : y) {
            t = min(t, w[z][2]);
        }
        for (auto z : y) {
            if (t == z) c++;
        }
        mp2[x] = {t, c};
    }

    int ans = 1e18;

    FOR(i, 1, n) {
        int len = w[i][1] - w[i][0] + 1;
        if (x - len == len && mp2[x - len].se == 1) {
            continue;
        }
        if (mp2[x - len].fi) {
            ans = min(ans, w[i][2] + mp2[x - len].fi);
        }
    }

    if (ans == 1e18) ans = -1;
    cout << ans << endl;
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