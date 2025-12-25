#include <bits/stdc++.h>
#include <iomanip>
#include <queue>
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

const double PI = acos(-1);
const double eps = 1e-8;

void solve() {
    int n, k;
    cin >> n >> k;

    auto dist = [&](int x1, int y1, int x2, int y2) {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    };

    priority_queue<double, V<double>, greater<double>> q;

    FOR(i, 1, n) {
        int a, b, r;
        cin >> a >> b >> r;
        if (dist(0, 0, a, b) < r * r) {
            double delta = r - sqrt(dist(0, 0, a, b));
            q.push(PI * delta * r * r);
        }
    }

    double ans = 0;

    while (sz(q) > k) {
        ans += q.top();
        q.pop();
    }

    cout << fixed << setprecision(12) << ans;
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