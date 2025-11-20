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
    V<int> a(n + 1, 0), p(n + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) {
        int x = i, y = a[i];
        x = find(x), y = find(y);
        if (x != y) {
            p[x] = y;
        }
    }

    int mx = 0, mn = 0;

    FOR(i, 1, n) {
        if (i == p[i]) {
            mx++;
        }
    }

    iota(ALL(p), 0ll);

    FOR(i, 1, n) {
        if (i != a[a[i]]) {
            int x = i, y = a[i];
            x = find(x), y = find(y);
            if (x != y) {
                p[x] = y;
            } else {
                mn++;
            }
        }
    }

    cout << min(mx, mn + 1) << ' ' << mx << endl;
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
