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

    V<array<int, 3>> w(m);

    FOR(i, 0, m - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = {c, a, b};
    }

    sort(ALL(w));

    V<int> p(n + 1, 0), siz(n + 1, 1);

    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    V<int> mn(n + 1, 1e18), mx(n + 1, 0);

    int ans = 1e18;

    FOR(i, 0, m - 1) {
        int a = w[i][1], b = w[i][2];
        a = find(a), b = find(b);
        if (siz[a] > siz[b]) swap(a, b);
        if (a != b) {
            p[a] = b;
            mn[b] = min({mn[b], mn[a], w[i][0]});
            mx[b] = max({mx[b], mx[a], w[i][0]});
            siz[b] += siz[a];
        }

        if (find(1) == find(n)) {
            ans = min(ans, mx[find(1)] + mn[find(1)]);
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
