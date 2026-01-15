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
    V<int> d(n + 1, 0);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        d[b]++;
    }

    queue<int> q;

    FOR(i, 1, n) {
        if (!d[i]) {
            q.push(i);
        }
    }

    V<int> ans;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        ans.eb(t);

        for (auto v : g[t]) {
            if ((--d[v]) == 0) {
                q.push(v);
            }
        }
    }

    FOR(i, 1, n) {
        if (d[i]) {
            cout << -1 << endl;
            RE;
        }
    }

    FOR(i, 0, sz(ans) - 1) cout << ans[i] << " \n"[i == sz(ans) - 1];
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