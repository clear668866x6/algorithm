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
    int n, x, y;
    cin >> n >> x >> y;

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int ans = 0;

    int l1 = 0, l2 = 0, l3 = 0, l4 = 0;

    auto calc = [&](int l, int r) {
        int ans = 0, cnt = 0;
        FOR(i, 1, n) {
            if (w[i] < l || w[i] > r)
                ans += cnt * (cnt + 1) / 2, cnt = 0;
            else
                cnt++;
        }
        if (cnt) ans += cnt * (cnt + 1) / 2;
        return ans;
    };

    cout << calc(y, x) - calc(y + 1, x) - calc(y, x - 1) + calc(y + 1, x - 1) << endl;
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
