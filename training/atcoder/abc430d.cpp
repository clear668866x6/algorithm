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
    set<array<int, 2>> s;
    s.insert({0, 0});
    int ans = 0;
    V<int> mn(n + 1, 1e18);

    FOR(i, 1, n) {
        auto it = s.upper_bound({w[i], -1});
        if (it != s.end()) {
            auto [val2, id2] = *it;
            it--;
            auto [val1, id1] = *it;

            ans -= mn[id1];
            ans -= mn[id2];
            int t1 = abs(w[i] - val1);
            int t2 = abs(w[i] - val2);
            mn[i] = min(t1, t2);
            ans += mn[i];
            mn[id1] = min(mn[id1], t1), mn[id2] = min(mn[id2], t2);
            ans += mn[id1], ans += mn[id2];
        } else {
            it--;
            auto [val, id] = *it;
            if (mn[id] != 1e18) {
                ans -= mn[id];
            }
            mn[id] = min(mn[id], abs(w[i] - val));
            ans += mn[id];
            mn[i] = abs(w[i] - val);
            ans += mn[i];
        }
        s.insert({w[i], i});
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