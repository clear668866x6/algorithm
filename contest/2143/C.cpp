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
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x > y) {
            g[b].eb(a);
            d[a]++;
        } else {
            g[a].eb(b);
            d[b]++;
        }
    }

    queue<int> q;
    V<int> ans(n + 1, 0);
    int num = 1;
    FOR(i, 1, n) {
        if (!d[i]) {
            q.push(i);
            ans[i] = num++;
        }
    }

    while (sz(q)) {
        int t = q.front();
        q.pop();

        for (auto j : g[t]) {
            if ((--d[j]) == 0) {
                q.push(j);
                ans[j] = num++;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
