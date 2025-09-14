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
    int n, R;
    cin >> n >> R;

    V<int> L(n + 1, 1);

    FOR(i, 1, n) cin >> L[i];

    V<int> pre(n + 1, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + L[i];

    int ans = 0;
    int t = 1e18;

    FORD(i, R + 1, n) {
        if (L[i] == 0) {
            t = i;
            break;
        }
    }

    if (t != 1e18) {
        ans = pre[t] - pre[R] + (t - R);
    }
    t = 1e18;

    FOR(i, 0, R) {
        if (L[i] == 0) {
            t = i;
            break;
        }
    }

    if (t != 1e18) {
        ans += (pre[R] - pre[t - 1] + (R - t + 1));
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