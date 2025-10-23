#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define int int64_t
// #define endl "\n"

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

    V<array<int, 2>> w(n + 1);

    FOR(i, 1, n) {
        cout << "? " << i << ' ' << n << ' ';
        FOR(j, 1, n) cout << j << ' ';
        cout << endl;
        int t;
        cin >> t;
        w[i] = {t, i};
    }

    sort(w.begin() + 1, w.end(), greater());

    V<int> ans;

    FOR(i, 1, n) {
        int u = w[i][1];
        if (!sz(ans)) {
            ans.eb(w[i][1]);
            continue;
        }

        int k = sz(ans);

        cout << "? " << ans[0] << " " << k + 1 << ' ' << u << ' ';
        for (auto x : ans) cout << x << ' ';
        cout << endl;
        int t;
        cin >> t;

        if (t > k) {
            ans.eb(u);
        }
    }

    cout << "! " << sz(ans) << ' ';
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
