#include <bits/stdc++.h>
#include <iomanip>
#include <queue>
using namespace std;

#define int int64_t
#define double long double
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
    int n, k, x;
    cin >> n >> k >> x;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    priority_queue<pair<double, int>> q;

    FOR(i, 1, n) {
        q.push({a[i], 1});
    }

    while (k) {
        auto [x, y] = q.top();
        q.pop();
        if (k - y >= 0) {
            k -= y;
            q.push({x / 2.0, y * 2});
        } else {
            q.push({x / 2.0, k * 2});
            q.push({x, y - k});
            k = 0;
        }
    }

    while (x) {
        auto [c, d] = q.top();
        q.pop();
        if (x - d > 0) {
            x -= d;
        } else {
            cout << fixed << setprecision(15) << c << endl;
            x = 0;
        }
    }
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
