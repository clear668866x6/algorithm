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
    int n = 3;

    V<array<int, 2>> c(n + 1);

    FOR(i, 1, n) cin >> c[i][0] >> c[i][1];
    int ans = abs(c[2][0] - c[1][0]) + abs(c[2][1] - c[1][1]);

    if (c[3][0] == c[2][0] && c[3][0] == c[1][0] && c[3][1] >= min(c[1][1], c[2][1]) &&
            c[3][1] <= max(c[1][1], c[2][1]) ||
        (c[3][1] == c[2][1] && c[3][1] == c[1][1] && c[3][0] >= min(c[1][0], c[2][0]) &&
         c[3][0] <= max(c[1][0], c[2][0]))) {
        ans += 2;
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
