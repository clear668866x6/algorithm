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
    int n, m, v;
    cin >> n >> m >> v;

    V<int> w(n + 1, 0), pre(n + 2, 0);

    FOR(i, 1, n) cin >> w[i];

    FOR(i, 1, n) pre[i] = pre[i - 1] + w[i];

    V<int> a(1, 0), b(1, n + 1);

    int tot = 0;

    FOR(i, 1, n) {
        if (tot + w[i] >= v) {
            tot = 0;
            a.eb(i);
        } else {
            tot += w[i];
        }
    }

    tot = 0;

    FORD(i, 1, n) {
        if (tot + w[i] >= v) {
            tot = 0;
            b.eb(i);
        } else {
            tot += w[i];
        }
    }

    bool f = false;
    int ans = 0;

    FOR(i, 0, m) {
        int j = m - i;
        if (j >= sz(b) || i >= sz(a)) continue;
        int l = a[i], r = b[j];
        if (l >= r) {
            continue;
        }
        l++, r--;
        f = 1;
        ans = max(ans, pre[r] - pre[l - 1]);
    }
    if (!f) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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
