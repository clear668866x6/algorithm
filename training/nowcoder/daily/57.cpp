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
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    auto calc = [&](int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); };

    if (calc(2, n, x1, y1) == calc(2, n, x2, y2)) {
        YES;
    } else if (x1 == 2 && y1 == n && x2 == 2 & y2 == n) {
        YES;
    } else if (x1 == 2 && y1 == n || (x2 == 2 && y2 == n)) {
        NO;
    } else if (x1 == x2 || y1 == y2) {
        NO;
    } else if (abs(y1 - y2) == 1 && max(y1, y2) + 1 < n) {
        YES;
    } else {
        NO;
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