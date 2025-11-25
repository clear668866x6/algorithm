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
    V<array<int, 3>> w(n + 1);
    map<int, V<array<int, 2>>> mp;
    FOR(i, 1, n - 1) cin >> w[i][0] >> w[i][1] >> w[i][2], mp[w[i][2]].pb({w[i][0], w[i][1]});
    V<array<int, 2>> q(m + 1);
    FOR(i, 1, m) cin >> q[i][0], q[i][1] = i;
    sort(q.begin() + 1, q.end());

    V<int> p(n + 1, 0), siz(n + 1, 1);
    V<int> ans(m + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    int lst = 1, tot = 0;

    FOR(i, 1, m) {
        int t = q[i][0];
        FOR(j, lst, t) {
            for (auto [x, y] : mp[j]) {
                if (x > y) swap(x, y);
                x = find(x), y = find(y);
                if (x != y) {
                    p[x] = y;
                    tot += siz[x] * siz[y];
                    siz[y] += siz[x];
                }
            }
        }
        lst = t + 1;

        ans[q[i][1]] = tot;
    }

    FOR(i, 1, m) cout << ans[i] << ' ';
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