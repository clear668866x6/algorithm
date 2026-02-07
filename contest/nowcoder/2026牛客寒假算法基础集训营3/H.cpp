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
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int t1 = xa * yb - xb * ya, t2 = ya - yb;

    int a = t2 * t2, b = 2 * t1 * t2, c = t1 * t1 - 16;

    if (a == 0) {
        if (c == 0) {
            cout << 0 << endl;
        } else {
            cout << "no answer" << endl;
        }
        RE;
    }

    i128 del = b * b - 4 * a * c;
    if (del < 0) {
        cout << "no answer" << endl;
    } else {
        double ans = (4.0 - t1) / t2;

        cout << fixed << setprecision(12) << ans << endl;
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