#include <bits/stdc++.h>
#include <queue>
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
    V<V<int>> g(n + 1), g2(n + 1);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
    }

    priority_queue<array<int, 2>, V<array<int, 2>>, greater<array<int, 2>>> q;
    V<int> d(n + 1, 1e18);
    d[1] = 1;
    q.push({d[1], 1});

    while (!q.empty()) {
        auto [ddd, ver] = q.top();
        q.pop();

        if (ddd > d[ver]) continue;

        for (auto v : g[ver]) {
            int dd = max(v, ddd);
            if (d[v] > dd) {
                d[v] = dd;
                q.push({d[v], v});
            }
        }
    }

    set<int> s;
    s.insert(1);
    int mx = 0;

    FOR(i, 1, n) {
        if (d[i] == 1e18) {
            mx = 1e18;
        } else {
            mx = max(mx, d[i]);
        }

        if (s.count(i)) {
            s.erase(i);
        }
        for (auto x : g[i]) {
            if (x > i) {
                s.insert(x);
            }
        }

        if (mx > i) {
            cout << -1 << endl;

        } else {
            cout << sz(s) << endl;
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