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
    V<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    FOR(i, 1, n) cin >> a[i] >> b[i] >> c[i];

    V<V<int>> g(n + 1), g2(n + 1);

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (i == j) continue;
            if (a[i] - a[j] == 0 && b[i] - b[j] == 0 && c[i] < c[j]) {
                g[i].eb(j);
                g2[j].eb(i);

            } else {
                int del = (b[i] - b[j]) * (b[i] - b[j]) - 4 * (a[i] - a[j]) * (c[i] - c[j]);
                if (del < 0) {
                    if (c[i] < c[j]) {
                        g[i].eb(j);
                        g2[j].eb(i);
                    }
                }
            }
        }
    }

    V<int> f1(n + 1, 0), f2(n + 1, 0);

    auto dfs = [&](auto &&dfs, int u) -> int {
        if (f1[u] != 0) return f1[u];
        int mx = 0;
        for (auto v : g[u]) {
            mx = max(mx, dfs(dfs, v) + 1);
        }
        return f1[u] = mx;
    };

    auto dfs2 = [&](auto dfs2, int u) -> int {
        if (f2[u] != 0) return f2[u];
        int mx = 0;
        for (auto v : g2[u]) {
            mx = max(mx, dfs2(dfs2, v) + 1);
        }
        return f2[u] = mx;
    };

    FOR(i, 1, n) {
        int t1 = dfs(dfs, i);
        int t2 = dfs2(dfs2, i);
        cout << (t1 + t2 + 1) << ' ';
    }

    cout << endl;
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
