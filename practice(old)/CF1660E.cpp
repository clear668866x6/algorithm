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

    V<V<char>> s(2 * n + 1, V<char>(2 * n + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> s[i][j];
            s[i][j] -= '0';
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            s[i + n][j] = s[i][j];
            s[i][j + n] = s[i][j];
            s[i + n][j + n] = s[i][j];
        }
    }

    V<V<int>> sum(n * 2 + 1, V<int>(n * 2 + 1, 0));

    FOR(i, 1, 2 * n) {
        FOR(j, 1, 2 * n) {
            sum[i][j] = sum[i - 1][j - 1] + s[i][j];
        }
    }

    int tot = 0;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            tot += (s[i][j]);
        }
    }

    int ans = 1e18;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            ans = min(ans, tot + n - 2 * (sum[i + n - 1][j + n - 1] - sum[i - 1][j - 1]));
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
