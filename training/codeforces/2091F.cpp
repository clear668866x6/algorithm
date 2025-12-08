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

constexpr int mod = 998244353;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;

    int dx = (int)sqrt(d * d - 1);

    V<V<char>> s(n + 1, V<char>(m + 1, 0));
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    V<V<int>> f(n + 1, V<int>(m + 1, 0));
    V<V<int>> sum(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, m) {
        if (s[n][i] == 'X') {
            f[n][i] = 1;
        }
        sum[n][i] = sum[n][i - 1] + f[n][i];
    }

    FOR(i, 1, m) {
        if (s[n][i] == 'X') {
            int l = max<int>(1, i - d), r = min(m, i + d);
            int t = f[n][i];
            f[n][i] += (sum[n][r] - sum[n][l - 1] - t);
            f[n][i] %= mod;
            if (f[n][i] < 0) f[n][i] += mod;
        }
    }

    FOR(i, 1, m) sum[n][i] = sum[n][i - 1] + f[n][i];

    FORD(i, 1, n - 1) {
        FOR(j, 1, m) {
            if (s[i][j] == 'X') {
                int l = max<int>(1, j - dx), r = min(m, j + dx);
                f[i][j] += (sum[i + 1][r] - sum[i + 1][l - 1]);
                f[i][j] %= mod;
                if (f[i][j] < 0) f[i][j] += mod;
            }
        }

        FOR(j, 1, m) {
            sum[i][j] = sum[i][j - 1] + f[i][j];
        }
        FOR(j, 1, m) {
            if (s[i][j] == 'X') {
                int l = max<int>(1, j - d), r = min(m, j + d);
                int t = f[i][j];
                f[i][j] += (sum[i][r] - sum[i][l - 1] - t);
                f[i][j] %= mod;
                if (f[i][j] < 0) f[i][j] += mod;
            }
        }
        FOR(j, 1, m) {
            sum[i][j] = sum[i][j - 1] + f[i][j];
        }
    }

    int ans = 0;

    FOR(i, 1, m) ans += f[1][i], ans %= mod;

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
