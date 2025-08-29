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

    struct E {
        int x, y;
        bool operator<(const E &t) const {
            return y < t.y;
        }
    };

    V<E> w(m);

    FOR(i, 0, m - 1) cin >> w[i].x >> w[i].y;

    if (m & 1) {
        NO;
        RE;
    }

    sort(ALL(w));

    FOR2(i, 1, m - 1, 2) {
        if (w[i].x != w[i - 1].x && w[i].y == w[i - 1].y) {
            continue;
        }
        if (w[i].x == w[i - 1].x && ((w[i].y - w[i - 1].y + 1) & 1)) {

            NO;
            RE;

        } else if (w[i].x != w[i - 1].x && !((w[i].y - w[i - 1].y + 1) & 1)) {
            NO;
            RE;

        } else if (i + 1 < m && w[i + 1].y == w[i].y && w[i + 1].x != w[i].x) {
            NO;
            RE;
        }
    }

    YES;
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
