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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    V<int> a(n1 + 1, 0), b(n2 + 1, 0), c(n3 + 1, 0);
    FOR(i, 1, n1) cin >> a[i];
    FOR(i, 1, n2) cin >> b[i];
    FOR(i, 1, n3) cin >> c[i];

    sort(a.begin() + 1, a.end(), greater());
    sort(b.begin() + 1, b.end(), greater());
    sort(c.begin() + 1, c.end(), greater());

    V f(n1 + 1, V<V<int>>(n2 + 1, V<int>(n3 + 1, 0)));

    int ans = 0;

    FOR(i, 0, n1) {
        FOR(j, 0, n2) {
            FOR(k, 0, n3) {
                if (i && j) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + a[i] * b[j]);
                }
                if (i && k) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i] * c[k]);
                }
                if (j && k) {
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1] + b[j] * c[k]);
                }
                ans = max(ans, f[i][j][k]);
            }
        }
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