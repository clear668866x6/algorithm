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
    int n, t, a, b;
    cin >> n >> t >> a >> b;
    V<int> w1(n + 1, 0), w2(n + 1, 0);
    FOR(i, 1, n) cin >> w1[i];
    FOR(i, 1, n) cin >> w2[i];

    int tot1 = 0, tot2 = 0, ans1 = 0, ans2 = 0;

    FOR(i, 1, n) {
        if (w2[i] < a) {
            if (w1[i] + tot1 <= t) {
                tot1 += w1[i];
                ans1++;
            }
        }

        if (w2[i] < b) {
            if (w1[i] + tot2 <= t) {
                tot2 += w1[i];
                ans2++;
            }
        } else {
            if (w1[i] * 2 + tot2 <= t) {
                tot2 += w1[i] * 2;
                ans2++;
            }
        }
    }

    cout << ans1 << ' ' << ans2;
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