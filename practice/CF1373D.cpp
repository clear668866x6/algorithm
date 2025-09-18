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
/*

dpi,0 表示长度为 i的前缀上的答案(如果我们没有开始反转子数组)
dpi,1 表示开始反转子数组但没有结束的答案
dpi,2 表示结束反转子数组的答案

*/
void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<V<int>> f(n + 1, V<int>(3, 0));

    FOR(i, 1, n) {
        if (i & 1) {
            f[i][0] = max(f[i][0], f[i - 1][0] + w[i]);
            if (i - 2 >= 0) {
                f[i][1] = max({f[i][1], max(f[i - 2][1], f[i - 2][0]) + w[i - 1]});
            }
            f[i][2] = max(f[i][2], max({f[i - 1][0], f[i - 1][1], f[i - 1][2]}) + w[i]);
        } else {
            f[i][0] = max(f[i][0], f[i - 1][0]);
            f[i][1] = max({f[i][1], max(f[i - 2][1], f[i - 2][0]) + w[i]});
            f[i][2] = max(f[i][2], max({f[i - 1][0], f[i - 1][1], f[i - 1][2]}));
        }
    }

    cout << max({f[n][0], f[n][1], f[n][2]}) << endl;
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
