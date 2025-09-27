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
    int t, m;
    cin >> t >> m;

    V<V<int>> f(5010, V<int>(5010, 0));

    FOR(i, 0, 5000) {
        FOR(j, 0, i) {
            if (!j)
                f[i][j] = 1;
            else
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % m;
        }
    }

    while (t--) {
        int n;
        cin >> n;
        V<int> w(n + 1, 0);
        FOR(i, 1, n) cin >> w[i];

        int ans = 1;
        int tot = accumulate(ALL(w), 0ll);
        FOR(i, 1, n) {
            (ans *= f[tot][w[i]]) %= m;
            tot -= w[i];
        }

        cout << ans << endl;
    }
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