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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    V<int> d(n + 1, 0);

    map<int, int> mp;

    int cnt = 0;

    if (x1 == x2 && y1 == y2) {
        cnt = 1;
    } else {
        cnt = 2;
    }

    V<int> vis(n + 1, 0);

    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        int lmn = min(x1, x2), lmx = max(x1, x2);
        int rmn = min(y1, y2), rmx = max(y1, y2);
        if (x >= lmn && x <= lmx && y >= rmn && y <= rmx) vis[i] = (lmx - lmn + 1) * (rmx - rmn + 1);
        d[i] = abs(x - x1) + abs(y - y1) + abs(x - x2) + abs(y - y2);
        mp[d[i]]++;
    }

    FOR(i, 1, n) {
        if (vis[i]) {
            cout << vis[i] - mp[d[i]] - cnt << ' ';
        } else {
            cout << 2 * d[i] - mp[d[i]] << ' ';
        }
    }

    cout << endl;
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
