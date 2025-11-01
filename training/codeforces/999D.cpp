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
    V<int> w(n + 1, 0);
    queue<array<int, 2>> q;
    V<V<int>> p(m + 1);
    FOR(i, 1, n) cin >> w[i], p[w[i] % m].eb(i);

    int t = n / m, cnt = 0;

    FOR(i, 0, 2 * m - 1) {
        int cur = i % m;
        while (sz(p[cur]) > t) {
            q.push({cur, p[cur].back()});
            p[cur].pop_back();
        }

        while (sz(p[cur]) < t) {
            if (!sz(q)) break;
            auto [x, y] = q.front();
            q.pop();
            p[cur].eb(y);
            if (x > cur) {
                int del = m - x + cur;
                cnt += del;
                w[y] += del;
            } else {
                int del = cur - x;
                cnt += del;
                w[y] += del;
            }
        }
    }

    cout << cnt << endl;

    FOR(i, 1, n) cout << w[i] << " ";
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