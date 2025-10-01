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
    FOR(i, 1, n) cin >> w[i];
    V<int> t(n + 1, 0), t2(n + 1, 0);
    FOR(i, 1, n) {
        t[i] = i - 2 * w[i];
        t2[i] = i + 2 * w[i];
    }

    int tot = 0;

    FOR(i, 1, n) {
        if (i & 1) {
            tot += w[i];
        } else {
            tot -= w[i];
        }
    }
    int ans = -1e18;

    priority_queue<int, V<int>, greater<int>> q;

    FOR(i, 1, n) {
        if (!(i & 1)) {
            ans = max(ans, tot + t2[i] - q.top());
        } else {
            q.push(t2[i]);
        }
    }

    while (sz(q)) q.pop();

    FOR(i, 1, n) {
        if ((i & 1) && i != 1) {
            ans = max(ans, tot + t[i] - q.top());
        } else if (i != 1) {
            q.push(t[i]);
        }
    }

    if (n & 1) {
        ans = max(ans, n - 1 + tot);
    } else {
        ans = max(ans, tot + n - 2);
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
