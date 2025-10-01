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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    priority_queue<int> q1;
    priority_queue<int, V<int>, greater<int>> q2;

    int pre = 0, ans = 0;

    FORD(i, 2, m) {
        q1.push(w[i]);
        pre += w[i];
        if (pre > 0) {
            int t = q1.top();
            q1.pop();
            pre -= 2 * t;
            ans++;
        }
    }
    pre = 0;

    FOR(i, m + 1, n) {
        q2.push(w[i]);
        pre += w[i];
        if (pre < 0) {
            int t = q2.top();
            q2.pop();
            pre -= 2 * t;
            ans++;
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
