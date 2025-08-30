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
    int rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;

    int n, m, l;
    cin >> n >> m >> l;

    V<pair<char, int>> segs(m), segt(l);

    for (auto &[x, y] : segs) cin >> x >> y;

    for (auto &[x, y] : segt) cin >> x >> y;

    set<int> p;
    p.insert(1);
    p.insert(n + 1);

    int x = rt - ra, y = ct - ca;

    int tot = 0;

    FOR(i, 0, m - 1) tot += segs[i].se, p.insert(tot + 1);
    tot = 0;
    FOR(i, 0, l - 1) tot += segt[i].se, p.insert(tot + 1);

    V<int> points(ALL(p));

    sort(ALL(points));

    V<int> sec(m), tec(l);
    V<char> sed(m), ted(l);

    tot = 0;

    FOR(i, 0, m - 1) {
        tot += segs[i].se;
        sec[i] = tot;
        sed[i] = segs[i].fi;
    }

    tot = 0;

    FOR(i, 0, l - 1) {
        tot += segt[i].se;
        tec[i] = tot;
        ted[i] = segt[i].fi;
    }

    int sidx = 0, tidx = 0;
    int tdx = 0, tdy = 0;
    int ans = 0;

    FOR(i, 0, sz(points) - 2) {
        int start = points[i], end = points[i + 1] - 1;
        if (start > end) continue;
        while (sidx < m && sec[sidx] < start) sidx++;
        while (tidx < l && tec[tidx] < start) tidx++;

        char a = sed[sidx], b = ted[tidx];

        int dx = 0, dy = 0;

        if (a == 'U')
            dx -= 1;
        else if (a == 'D')
            dx += 1;
        else if (a == 'L')
            dy -= 1;
        else if (a == 'R')
            dy += 1;
        if (b == 'U')
            dx += 1;
        else if (b == 'D')
            dx -= 1;
        else if (b == 'L')
            dy += 1;
        else if (b == 'R')
            dy -= 1;

        int cura = tdx + x, curb = tdy + y;

        int len = end - start + 1;

        if (!dx && !dy) {
            if (!cura && !curb) ans += len;
        } else if (!dx) {
            if (!cura && curb % dy == 0) {
                int k = -curb / dy;
                if (k >= 1 && k <= len) ans++;
            }
        } else if (!dy) {
            if (!curb && cura % dx == 0) {
                int k = -cura / dx;
                if (k >= 1 && k <= len) ans++;
            }
        } else {
            if (cura % dx == 0 && curb % dy == 0) {
                int k1 = -cura / dx, k2 = -curb / dy;
                if (k1 == k2 && k1 >= 1 && k1 <= len) ans++;
            }
        }

        tdx += dx * len, tdy += dy * len;
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