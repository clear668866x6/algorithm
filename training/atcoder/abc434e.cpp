#include <algorithm>
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
// 二选一可以用图表示，如果我选1个的话，那么一条边连向另一条边。
void solve() {
    int n;
    cin >> n;

    V<int> l(n + 1, 0), r(n + 1, 0);

    V<int> d;

    FOR(i, 1, n) {
        int x, c;
        cin >> x >> c;
        l[i] = x - c, r[i] = x + c;
        d.eb(l[i]), d.eb(r[i]);
    }

    sort(ALL(d));
    d.erase(unique(ALL(d)), d.end());

    auto get = [&](int x) { return lower_bound(ALL(d), x) - d.begin() + 1; };

    V<int> p(2 * n + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    V<int> e(n * 2 + 1, 0), v(n * 2 + 1, 0);

    FOR(i, 1, 2 * n) v[i] = 1;

    FOR(i, 1, n) {
        int a = find(get(l[i])), b = find(get(r[i]));
        if (a == b) {
            e[a]++;
            continue;
        }
        p[a] = b;
        e[b] += e[a] + 1;
        v[b] += v[a];
    }

    int ans = 0;

    FOR(i, 1, 2 * n) {
        if (i == p[i]) {
            if (v[i] == e[i] + 1) {
                ans += e[i];
            } else {
                ans += v[i];
            }
        }
    }

    cout << ans;
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