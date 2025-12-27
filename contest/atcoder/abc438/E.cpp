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
    int n, q;
    cin >> n >> q;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    V<V<int>> next(63, V<int>(n + 1, 0)), s(63, V<int>(n + 1, 0));

    FOR(i, 1, n) {
        next[0][i] = a[i];
        s[0][i] = i;
    }

    FOR(k, 1, 60) {
        FOR(i, 1, n) {
            next[k][i] = next[k - 1][next[k - 1][i]];
            s[k][i] = s[k - 1][i] + s[k - 1][next[k - 1][i]];
        }
    }

    while (q--) {
        int t, x;
        cin >> t >> x;

        int ans = 0, cur = x;

        FOR(k, 0, 60) {
            if (t >> k & 1) {
                ans += s[k][cur];
                cur = next[k][cur];
            }
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