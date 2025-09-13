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

    V<V<int>> w(n);

    int mx = 0;

    FOR(i, 0, n - 1) {
        int k;
        cin >> k;
        mx = max(mx, k);
        FOR(j, 0, k - 1) {
            int x;
            cin >> x;
            w[i].eb(x);
        }
    }

    sort(ALL(w), [&](V<int> a, V<int> b) {
        int mn = min(sz(a), sz(b));
        FOR(i, 0, mn - 1) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return sz(a) < sz(b);
    });

    V<int> ans(mx, 0);

    for (auto x : w) {
        FOR(j, 0, sz(x) - 1) {
            if (!ans[j]) {
                ans[j] = x[j];
            }
        }
    }
    FOR(i, 0, mx - 1) cout << ans[i] << " \n"[i == mx - 1];
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
