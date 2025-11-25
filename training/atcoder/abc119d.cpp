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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    V<int> a(n + 1, 0), b(m + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    ranges::sort(a), ranges::sort(b);

    while (q--) {
        int x;
        cin >> x;
        int ans = 1e18;
        auto it1 = lower_bound(ALL(a), x);
        auto it2 = lower_bound(ALL(b), x);
        V<int> c1, c2;
        if (it1 == a.end()) {
            int l = *prev(it1);
            c1.eb(l);
        } else {
            int p1 = *it1, p2 = *prev(it1);
            c1.eb(p1);
            c1.eb(p2);
        }
        if (it2 == b.end()) {
            int r = *prev(it2);
            c2.eb(r);
        } else {
            int p1 = *it2, p2 = *prev(it2);
            c2.eb(p1);
            c2.eb(p2);
        }

        FOR(i, 0, sz(c1) - 1) {
            FOR(j, 0, sz(c2) - 1) {
                int t1 = c1[i], t2 = c2[j];
                if (!t1 || !t2) continue;
                if (max(t1, t2) <= x) {
                    ans = min(ans, x - min(t1, t2));
                } else if (min(t1, t2) >= x) {
                    ans = min(ans, max(t1, t2) - x);
                } else {
                    ans = min(ans, min(abs(x - t1), abs(x - t2)) + max(t1, t2) - min(t2, t1));
                }
            }
        }

        cout << ans << endl;
    }
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