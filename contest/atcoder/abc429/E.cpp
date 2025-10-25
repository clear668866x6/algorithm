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
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n + 1);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    string s;
    cin >> s;
    s = ' ' + s;

    priority_queue<TII, V<TII>, greater<TII>> q;
    V<int> d1(n + 1, 1e18), d2(n + 1, 1e18);
    V<int> p1(n + 1, 0), p2(n + 1, 0);

    FOR(i, 1, n) {
        if (s[i] == 'S') {
            q.push({0, i, i});
            d1[i] = 0;
            p1[i] = i;
        }
    }

    while (!q.empty()) {
        auto [d, ver, p] = q.top();
        q.pop();

        if (d > d2[ver]) continue;

        for (auto j : g[ver]) {
            int nd = d + 1;
            if (d1[j] > nd) {
                d2[j] = d1[j];
                p2[j] = p1[j];
                d1[j] = nd;
                p1[j] = p;
                q.push({nd, j, p});
            } else if (d2[j] > nd && p != p1[j]) {
                d2[j] = nd;
                p2[j] = p;
                q.push({nd, j, p});
            }
        }
    }

    FOR(i, 1, n) {
        if (s[i] == 'D') {
            int ans = 1e18;
            ans = min({ans, d1[i] + d2[i]});
            cout << ans << endl;
        }
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