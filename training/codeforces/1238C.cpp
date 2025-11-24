#include <algorithm>
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
    int h, n;
    cin >> h >> n;
    V<int> w(n + 1, 0);
    set<int> s;
    FOR(i, 1, n) cin >> w[i], s.insert(w[i]);
    s.insert(0);

    int ans = 0;

    while (h >= 2) {
        auto it1 = prev(s.upper_bound(h));
        auto it2 = prev(it1);
        int t1 = *it1, t2 = *it2;
        if (t1 == t2 + 1) {
            h -= 2;
            if (!s.count(h)) {
                ans++;
            }
            s.insert(h);
        } else {
            h = t2 + 1;
            s.insert(h);
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
