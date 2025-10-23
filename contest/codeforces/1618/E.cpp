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

    int tot = 0;

    FOR(i, 1, n) cin >> w[i], tot += w[i];

    if (tot % (n * (n + 1) / 2)) {
        No;
        RE;
    }

    V<int> ans(n + 1, 0);

    FOR(i, 1, n) {
        if (i == 1) {
            int t = (w[n] - w[1]) + tot / (n * (n + 1) / 2);
            if (t <= 0 || t % n) {
                NO;
                RE;
            }
            ans[i] = t / n;
        } else {
            int t = (w[i - 1] - w[i]) + tot / (n * (n + 1) / 2);
            if (t <= 0 || t % n) {
                NO;
                RE;
            }

            ans[i] = t / n;
        }
    }
    YES;

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
