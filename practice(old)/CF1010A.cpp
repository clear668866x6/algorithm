#include <bits/stdc++.h>
#include <iomanip>
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

    V<int> a(n + 1, 0), b(n + 2, 0);

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    b[n + 1] = b[1];

    double l = 0, r = 1e9 + 2;

    auto check = [&](double x) {
        double tot = m + x;

        FOR(i, 1, n) {
            double t1 = tot / (double)a[i], t2 = (tot - t1) / (double)b[i + 1];
            tot -= t1;
            tot -= t2;
            if (tot < m) return 0;
        }

        return 1;
    };

    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (r == 1e9 + 2) {
        cout << -1;
    } else {
        cout << setprecision(12) << fixed << r << endl;
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