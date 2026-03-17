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
    int l, r;
    cin >> l >> r;

    int ans = 0, n = 2e7;

    V<int> npr(n + 10, 0), vis(n + 10, 0);

    FOR(i, 2, n) {
        if (!npr[i]) {
            for (int j = (l / i + 1) * i; j <= r; j += i) {
                vis[j - l] = 1;
                int cur = j;
                while (cur % i == 0) cur /= i;
                if (cur == 1) ans++;
            }

            for (int j = 2 * i; j <= n; j += i) {
                npr[j] = 1;
            }
        }
    }

    FOR(i, l, r) {
        ans += !vis[i - l];
    }

    cout << ans;
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