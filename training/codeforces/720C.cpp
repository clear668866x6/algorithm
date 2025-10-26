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
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0), b(m, 0);
    set<int> s;
    FOR(i, 1, n) cin >> a[i], s.insert(a[i]);
    FOR(i, 0, m - 1) cin >> b[i];

    int l = -1, r = 1e12;

    auto check = [&](int x) {
        int cnt = 0;

        FOR(i, 1, n) {
            auto it = lower_bound(ALL(b), a[i]);
            int t = 1e18;
            if (it != b.end()) {
                t = min(t, abs(*it - a[i]));
            }
            if (it != b.begin()) {
                t = min(t, abs(*prev(it) - a[i]));
            }

            if (t <= x) {
                cnt++;
            }
        }
        return cnt >= n;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
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