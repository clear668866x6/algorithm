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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i], w[i] %= 3;

    int c0 = 0, c1 = 0, c2 = 0;

    FOR(i, 1, n) c0 += (w[i] == 0), c1 += (w[i] == 1), c2 += (w[i] == 2);

    int t = n / 3;

    int ans = 0;

    while (1) {
        if (c0 == c1 && c0 == c2) break;
        if (c0 > t) {
            ans += (c0 - t);
            c1 += (c0 - t);
            c0 = t;
        }
        if (c1 > t) {
            ans += (c1 - t);
            c2 += (c1 - t);
            c1 = t;
        }
        if (c2 > t) {
            ans += (c2 - t);
            c0 += (c2 - t);
            c2 = t;
        }
    }

    cout << ans << endl;
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
