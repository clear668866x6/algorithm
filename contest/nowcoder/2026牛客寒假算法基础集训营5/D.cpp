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

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    priority_queue<array<int, 2>, V<array<int, 2>>, greater<array<int, 2>>> q;

    FOR(i, 1, n) {
        int c, w;
        cin >> c >> w;
        q.push({w, c});
    }

    int ans = 0;

    while (sz(q) > 1) {
        auto [x1, y1] = q.top();
        q.pop();
        if (y1 & 1) {
            auto [x2, y2] = q.top();
            q.pop();
            ans += (x1 * 2) * (y1 / 2) % mod;
            ans %= mod;
            ans += (x1 + x2) % mod;
            ans %= mod;
            if (y2 - 1) {
                q.push({x2, y2 - 1});
            }
            if (y1 / 2) {
                q.push({x1 * 2, y1 / 2});
            }
            q.push({x1 + x2, 1});
        } else {
            ans += (x1 * 2) * (y1 / 2) % mod;
            ans %= mod;
            if (y1 / 2) {
                q.push({x1 * 2, y1 / 2});
            }
        }
    }

    cout << ans << endl;
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