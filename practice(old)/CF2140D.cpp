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
    V<array<int, 3>> w(n);
    FOR(i, 0, n - 1) {
        int l, r;
        cin >> l >> r;
        w[i] = {l + r, l, r};
    }

    sort(ALL(w));
    int ans = 0;
    FOR(i, 0, n - 1) ans += (w[i][2] - w[i][1]);

    if (n & 1) {
        int t = ans;

        FOR(i, 0, n / 2 - 1) t -= w[i][1];
        FOR(i, n / 2 + 1, n - 1) t += w[i][2];

        FOR(i, 0, n - 1) {
            if (i < n / 2) {
                ans = max(ans, t + (w[i][1] - w[n / 2][1]));
            } else {
                ans = max(ans, t - w[i][2] + w[n / 2][2]);
            }
        }
    } else {

        FOR(i, 0, n / 2 - 1) {
            ans -= w[i][1];
        }

        FOR(i, n / 2, n - 1) ans += w[i][2];
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
