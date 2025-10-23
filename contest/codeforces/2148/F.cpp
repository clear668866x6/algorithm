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

    V<int> ans(mx, 0);

    int pos = 0;

    while (pos < mx) {
        sort(ALL(w));
        FOR(i, 0, sz(w[0]) - 1) {
            ans[pos++] = w[0][i];
        }

        int k = sz(w[0]);
        V<V<int>> b;
        FOR(i, 0, sz(w) - 1) {
            V<int> c;
            FOR(j, k, sz(w[i]) - 1) {
                c.eb(w[i][j]);
            }
            if (sz(c)) {
                b.eb(c);
            }
        }
        w = b;
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
