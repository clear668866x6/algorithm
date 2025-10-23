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
    string s;
    cin >> n >> s;

    s = ' ' + s;

    V<V<int>> f(n + 1, V<int>(n + 1, 0));

    f[1][1] = 1;
    int mod = 1e9 + 7;

    FOR(i, 2, n) {
        V<int> sum(n + 1, 0);
        FOR(j, 1, i) {
            sum[j] = (sum[j - 1] + f[i - 1][j]) % mod;
        }
        if (s[i - 1] == '<') {
            FOR(j, 1, i) {
                (f[i][j] += (sum[j - 1])) %= mod;
            }
        } else {
            FOR(j, 1, i) {
                (f[i][j] += (sum[i - 1] - sum[j - 1] + mod) % mod) %= mod;
                // 这里是j而不是j+1的原因：为了确保填入 j 后仍然是一个 1∼i 的排列,
                // 我们需要对前 i− 1 个数中所有大于等于 j 的数加 1。这样，数字 j 就可以插入而不重复。
                // 其实就是可能会在前面1~i里面会有比如取n值还满足题意的情况出现
            }
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        (ans += f[n][i]) %= mod;
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