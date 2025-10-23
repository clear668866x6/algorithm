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

    V<V<PII>> g(n + 1);

    FOR(i, 1, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].eb(b, c);
        g[b].eb(a, c);
    }

    V<int> vis(n + 1, 0);

    struct E {
        int d, ver, used;
        bool operator<(const E &t) const {
            return d > t.d;
        }
    };

    priority_queue<E> q;

    V<V<int>> d(n + 1, V<int>(2, 1e18));
    d[1][0] = 0;

    q.push({0, 1, 0});

    while (sz(q)) {
        auto [dd, ver, used] = q.top();
        q.pop();

        for (auto [j, w] : g[ver]) {
            if (used) {
                if (d[j][0] > d[ver][1]) {
                    d[j][0] = d[ver][1];
                    q.push({d[j][0], j, 0});
                }
            } else {
                if (d[j][0] > d[ver][0] + w) {
                    d[j][0] = d[ver][0] + w;
                    q.push({d[j][0], j, 0});
                }
                if (d[j][1] > d[ver][0] + 2 * w) {
                    d[j][1] = d[ver][0] + 2 * w;
                    q.push({d[j][1], j, 1});
                }
            }
        }
    }

    cout << min(d[n][0], d[n][1]);
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