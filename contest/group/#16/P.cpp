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
    int n, m;
    cin >> n >> m;

    V<array<int, 2>> w(n);

    int t = 0;

    V<int> ans(n, 0);

    FOR(i, 0, n - 1) {
        cin >> w[i][0];
        w[i][1] = i;
        t += (w[i][0] + 1) / 2;
    }

    if (t > m) {
        cout << -1 << endl;
        RE;
    }

    FOR(i, 0, n - 1) ans[i] = (w[i][0] + 1) / 2;

    m -= t;

    sort(ALL(w));

    FORD(i, 0, n - 1) {
        if (m - (w[i][0] - ans[w[i][1]]) >= 0) {
            m -= (w[i][0] - ans[w[i][1]]);
            ans[w[i][1]] = w[i][0];
        } else {
            ans[w[i][1]] += m;
            m = 0;
            break;
        }
    }

    if (m) {
        cout << -1 << endl;
    } else {
        FOR(i, 0, n - 1) cout << ans[i] << " ";
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