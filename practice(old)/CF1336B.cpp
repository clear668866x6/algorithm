#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    V<int> a(n1 + 1, 0), b(n2 + 1, 0), c(n3 + 1, 0);
    FOR(i, 1, n1) cin >> a[i];
    FOR(i, 1, n2) cin >> b[i];
    FOR(i, 1, n3) cin >> c[i];

    sort(ALL(a)), sort(ALL(b)), sort(ALL(c));
    a.erase(unique(ALL(a)), a.end());
    b.erase(unique(ALL(b)), b.end());
    c.erase(unique(ALL(c)), c.end());

    int inf = numeric_limits<int>::max();
    int ans = inf;

    auto calc = [&](int x, int y, int z) { return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z); };

    auto work1 = [&](auto it1, auto it2, int cb) {
        if (it1 == a.end() || !(*it1)) RE;
        if (it2 == c.end() || !(*it2)) RE;
        int ca = *it1, cc = *it2;
        ans = min(ans, calc(ca, cb, cc));
    };
    auto work2 = [&](auto it1, auto it2, int ca) {
        if (it1 == b.end() || !(*it1)) RE;
        if (it2 == c.end() || !(*it2)) RE;
        int cb = *it1, cc = *it2;
        ans = min(ans, calc(ca, cb, cc));
    };
    auto work3 = [&](auto it1, auto it2, int cc) {
        if (it1 == a.end() || !(*it1)) RE;
        if (it2 == b.end() || !(*it2)) RE;
        int ca = *it1, cb = *it2;
        ans = min(ans, calc(ca, cb, cc));
    };

    n1 = sz(a) - 1, n2 = sz(b) - 1, n3 = sz(c) - 1;

    FOR(i, 1, n2) {
        auto it1 = lower_bound(ALL(a), b[i]);
        auto it2 = lower_bound(ALL(c), b[i]);
        int cb = b[i];
        work1(it1, it2, cb);
        work1(prev(it1), it2, cb);
        work1(it1, prev(it2), cb);
        work1(prev(it1), prev(it2), cb);
        if (it1 != a.end()) {
            work1(next(it1), it2, cb);
            if (it2 != c.end()) {
                work1(next(it1), next(it2), cb);
            }
            work1(next(it1), prev(it2), cb);
        }
        if (it2 != c.end()) {
            work1(it1, next(it2), cb);
            work1(prev(it1), next(it2), cb);
        }
    }

    FOR(i, 1, n1) {
        auto it1 = lower_bound(ALL(b), a[i]);
        auto it2 = lower_bound(ALL(c), a[i]);
        int cb = a[i];
        work2(it1, it2, cb);
        work2(prev(it1), it2, cb);
        work2(it1, prev(it2), cb);
        work2(prev(it1), prev(it2), cb);
        if (it1 != b.end()) {
            work2(next(it1), it2, cb);
            if (it2 != c.end()) {
                work2(next(it1), next(it2), cb);
            }
            work2(next(it1), prev(it2), cb);
        }
        if (it2 != c.end()) {
            work2(it1, next(it2), cb);
            work2(prev(it1), next(it2), cb);
        }
    }

    FOR(i, 1, n3) {
        auto it1 = lower_bound(ALL(a), c[i]);
        auto it2 = lower_bound(ALL(b), c[i]);
        int cb = c[i];
        work3(it1, it2, cb);
        work3(prev(it1), it2, cb);
        work3(it1, prev(it2), cb);
        work3(prev(it1), prev(it2), cb);
        if (it1 != a.end()) {
            work3(next(it1), it2, cb);
            if (it2 != b.end()) {
                work3(next(it1), next(it2), cb);
            }
            work3(next(it1), prev(it2), cb);
        }
        if (it2 != b.end()) {
            work3(it1, next(it2), cb);
            work3(prev(it1), next(it2), cb);
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
