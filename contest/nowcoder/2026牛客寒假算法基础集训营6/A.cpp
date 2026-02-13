#include <bits/stdc++.h>
#include <iomanip>
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
    int n, w;
    cin >> n >> w;
    V<int> x(n + 1, 0), y(n + 1, 0);

    auto get = [&](int x, int y) { return sqrtl(x * x + y * y); };

    FOR(i, 1, n) cin >> x[i] >> y[i];

    struct E {
        double val;
        int idx;
        bool operator<(const E &t) const {
            return val < t.val;
        }
    };

    priority_queue<E> q;

    FOR(i, 1, n) {
        double t = get(x[i], y[i]) - get(x[i], y[i] - 1);
        q.push({t, i});
    }

    FOR(i, 1, w) {
        if (q.empty()) break;
        auto [yy, idx] = q.top();
        q.pop();
        if (y[idx] - 1 >= 0) {
            y[idx]--;
            if (y[idx]) {
                double del = get(x[idx], y[idx]);
                del -= get(x[idx], y[idx] - 1);
                q.push({del, idx});
            }
        }
    }

    double ans = 0;

    FOR(i, 1, n) {
        ans += get(x[i], y[i]);
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