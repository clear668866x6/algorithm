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

    if (n <= 2) {
        cout << 0 << endl;
        RE;
    }

    int tot = 0;

    FOR(i, 2, n - 1) {
        if (w[i] > w[i - 1] && w[i] > w[i + 1]) tot++;
        if (w[i] < w[i - 1] && w[i] < w[i + 1]) tot++;
    }

    int ans = tot;

    FOR(i, 1, n) {
        if (i == 1) {
            if (w[i + 1] > w[i] && w[i + 1] > w[i + 2] || (w[i + 1] < w[i] && w[i + 1] < w[i + 2])) {
                ans = min(ans, tot - 1);
            }
        } else if (i == n) {
            if (w[i - 1] > w[i] && w[i - 1] > w[i - 2] || (w[i - 1] < w[i] && w[i - 1] < w[i - 2])) {
                ans = min(ans, tot - 1);
            }
        } else {
            if (w[i - 1] == w[i + 1]) {
                if (w[i] > w[i - 1]) {
                    int t = 0;
                    if (i - 2 >= 1 && w[i - 2] > w[i - 1]) t++;
                    if (i + 2 <= n && w[i + 2] > w[i + 1]) t++;
                    ans = min(ans, tot - t - 1);
                } else if (w[i] < w[i - 1]) {
                    int t = 0;
                    if (i - 2 >= 1 && w[i - 2] < w[i - 1]) t++;
                    if (i + 2 <= n && w[i + 2] < w[i + 1]) t++;
                    ans = min(ans, tot - t - 1);
                }
            } else {
                //[TODO]我当时在这里就感觉讨论起来比较困难了，然后就猜了一个结论，但是是错的。太理想化了，但我想到了中间的那个值等于左边或者右边，我以为能全部置0（因为我就举了两个例子）
                auto check = [&](int x) {
                    if (x - 1 >= 1 && x + 1 <= n) {
                        if (w[x - 1] > w[x] && w[x + 1] > w[x]) return 1;
                        if (w[x - 1] < w[x] && w[x + 1] < w[x]) return 1;
                        return 0;
                    }
                    return 0;
                };

                int t = w[i];
                int p = check(i - 1) + check(i) + check(i + 1);
                w[i] = w[i - 1];
                int pp = p - (check(i - 1) + check(i) + check(i + 1));

                ans = min(ans, tot - pp);

                w[i] = w[i + 1];
                pp = p - (check(i - 1) + check(i) + check(i + 1));

                ans = min(ans, tot - pp);

                w[i] = t;
            }
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
