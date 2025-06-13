#include <bits/stdc++.h>
#define int int64_t
#define endl "\n"

using PII = std::pair<int, int>;
using TII = std::tuple<int, int, int>;
template<class T>
using V = std::vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n, k;
    std::cin >> n >> k;
    V<double>w (n + 1);

    FOR (i, 1, n)std::cin >> w[i];

    if (n == k) {
        std::cout << "0.00000000";
        RE;
    }

    std::ranges::sort (w);

    if (k == 1) {
        std::cout << w[n] - w[1];
    }
    else {

        V<int>s (n + 2, 0);

        FOR (i, 1, n)s[i] = s[i - 1] + w[i];

        double ans = std::numeric_limits<double>::max ();

        FOR (i, 0, k) {
            int j = k - i;
            int t = s[i] + s[n] - s[n - j];
            double mx = std::max<double> (w[n - j], t * 1. / (double)k);
            double mn = std::min<double> (w[i + 1], t * 1. / (double)k);
            ans = std::min<double> (ans, mx - mn);
        }
        std::cout << std::fixed << std::setprecision (10) << ans;
    }

}

signed main () {
    int Task = 1;

    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}