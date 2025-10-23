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
    int n, d, a;
    cin >> n >> d >> a;

    struct E {
        int x, h;
        bool operator<(const E &t) const {
            return x < t.x;
        }
    };

    V<E> w(n + 1);

    FOR(i, 1, n) cin >> w[i].x >> w[i].h;

    sort(w.begin() + 1, w.end());

    V<int> b(n + 3, 0);

    int ans = 0;

    FOR(i, 1, n) {
        b[i] += b[i - 1];
        int val = w[i].h - b[i] * a;
        if (val <= 0) continue;
        int cnt = (val + a - 1) / a;
        ans += cnt;
        b[i + 1] += cnt;

        int tt = upper_bound(ALL(w), E{w[i].x + 2 * d, -1}) - w.begin() - 1;
        // cout << tt << endl;
        b[tt + 1] -= cnt;
    }

    cout << ans;
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