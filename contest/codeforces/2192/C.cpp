#include <bits/stdc++.h>
#include <numeric>
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
    int n, h, k;
    cin >> n >> h >> k;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    int tot = accumulate(ALL(a), 0ll);
    if (h % tot == 0) {
        cout << (h / tot) * (n + k) - k << endl;
        RE;
    }
    int ans = (h / tot) * (n + k);
    h %= tot;

    V<int> s(n + 1, 0);
    FOR(i, 1, n) s[i] = s[i - 1] + a[i];

    int idx = 1;

    FOR(i, 1, n) {
        if (s[i] >= h) {
            idx = i;
            break;
        }
    }

    int mn = 1e18;
    V<int> suf(n + 2, 0);
    FORD(i, 1, n) suf[i] = max(suf[i + 1], a[i]);

    FOR(i, 1, n) {
        mn = min(mn, a[i]);
        if (s[i] >= h) {
            cout << ans + i << endl;
            RE;
        }
        if (s[i] - mn + suf[i + 1] >= h) {
            cout << ans + i << endl;
            RE;
        }
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
