#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int l, r;
    cin >> l >> r;

    if (r <= 2 || ((r - 1) >= l && (r - 1) == 2)) {
        cout << -1 << endl;
        RE;
    }

    if (!(r & 1)) {
        cout << r / 2 << ' ' << r / 2 << endl;
    } else if (r - 1 >= l && (r & 1)) {
        cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << endl;
    } else {
        int x = 0;
        FOR(i, 2, l / i) {
            if (l % i == 0) {
                x = i;
                break;
            }
        }
        if (!x) {
            cout << -1 << endl;
            RE;
        }
        int t = l / x;

        cout << t << ' ' << (r - t) << endl;
    }
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
