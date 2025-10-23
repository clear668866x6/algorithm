#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
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
    int n;
    cin >> n;

    V<V<int>> g(n + 1);
    V<int> d(n + 1, 0), din(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        din[a]++, din[b]++;
        g[a].eb(b);
        g[b].eb(a);
    }

    FOR(i, 1, n) {
        if (sz(g[i]) == n - 1) {
            cout << 0 << endl;
            RE;
        }
    }

    int ans = 1e18, cnt = 0;

    FOR(i, 1, n) {
        if (sz(g[i]) == 1)
            cnt++;
    }

    FOR(i, 1, n) {
        int t = cnt;
        for (auto j : g[i]) {
            if (sz(g[j]) == 1)
                t--;
        }
        ans = min(ans, t);
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