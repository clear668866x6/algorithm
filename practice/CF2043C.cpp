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
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    bool f = false;

    int idx = n + 1;
    FOR(i, 1, n) {
        if (abs(a[i]) > 1) {
            idx = i;
            f = 1;
        }
    }

    V<int> mx(n + 2, -1e18), mn(n + 2, 1e18);

    int mx1 = -1e18, mx2 = -1e18, mn1 = 1e18, mn2 = 1e18;

    FOR(i, 1, idx - 1) {
        mx[i] = max({mx[i - 1] + a[i], a[i]});
        mx1 = max(mx1, mx[i]);
    }

    FORD(i, idx + 1, n) {
        mx[i] = max({mx[i + 1] + a[i], a[i]});
        mx2 = max(mx2, mx[i]);
    }

    FOR(i, 1, idx - 1) {
        mn[i] = min({mn[i - 1] + a[i], a[i]});
        mn1 = min(mn1, mn[i]);
    }
    FORD(i, idx + 1, n) {
        mn[i] = min({mn[i + 1] + a[i], a[i]});
        mn2 = min(mn2, mn[i]);
    }

    set<int> ans;
    ans.insert(0);

    FOR(i, mn1, mx1) ans.insert(i);
    if (f) FOR(i, mn2, mx2) ans.insert(i);

    if (f) {
        V<int> s(n + 1, 0);
        FOR(i, 1, n) s[i] = s[i - 1] + a[i];
        int mx1 = -1e18, mx2 = -1e18, mn1 = 1e18, mn2 = 1e18;

        FORD(i, 1, idx) {
            mx1 = max(mx1, s[idx - 1] - s[i - 1]);
            mn1 = min(mn1, s[idx - 1] - s[i - 1]);
        }

        FOR(i, idx, n) {
            mx2 = max(mx2, s[i] - s[idx]);
            mn2 = min(mn2, s[i] - s[idx]);
        }

        FOR(i, a[idx] + mn1 + mn2, a[idx] + mx1 + mx2) {
            ans.insert(i);
        }
    }

    cout << sz(ans) << endl;
    for (auto x : ans) cout << x << ' ';
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
