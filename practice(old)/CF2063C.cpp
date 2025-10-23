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
    int n;
    cin >> n;
    V<V<int>> g(n + 1);
    V<int> d(n + 1, 0);
    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
        d[a]++, d[b]++;
    }

    // 假的贪心
    //  int mx = 0;
    //  FOR(i, 1, n) {
    //      if (d[i] > d[mx]) {
    //          mx = i;
    //      }
    //  }

    // int ans = d[mx] + 1 - 1;

    // // cout << ans << endl;
    // d[mx] = 0;
    // for (auto j : g[mx]) {
    //     d[j]--;
    // }
    // mx = 0;
    // FOR(i, 1, n) {
    //     if (d[i] > d[mx]) {
    //         mx = i;
    //     }
    // }

    // ans += d[mx] - 1;

    // cout << ans << endl;

    multiset<int> s;

    FOR(i, 1, n) s.insert(d[i]);

    int ans = 0;

    FOR(i, 1, n) {
        s.erase(s.find(d[i]));
        int res = d[i];
        for (auto j : g[i]) {
            s.erase(s.find(d[j]));
            d[j]--;
            s.insert(d[j]);
        }
        res += (*s.rbegin() - 1);
        ans = max(ans, res);
        s.insert(d[i]);
        for (auto j : g[i]) {
            s.erase(s.find(d[j]));
            d[j]++;
            s.insert(d[j]);
        }
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
