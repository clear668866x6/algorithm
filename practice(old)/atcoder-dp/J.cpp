// 期望dp是 f[i]=(f[j]+1)*p
#include <bits/stdc++.h>
#include <iomanip>
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
    V<int> a(n + 1, 0);
    map<int, int> mp;
    FOR(i, 1, n) cin >> a[i], mp[a[i]]++;

    V<V<V<double>>> f(n + 2, V<V<double>>(n + 2, V<double>(n + 2, 0)));

    FOR(k, 0, n) {
        FOR(j, 0, n) {
            FOR(i, 0, n) {
                if (!i && !j && !k) continue;
                int tot = i + j + k;
                if (i) {
                    f[i][j][k] += (double)i / (double)tot * (f[i - 1][j][k]);
                }
                if (j) {
                    f[i][j][k] += (double)j / (double)tot * (f[i + 1][j - 1][k]);
                }
                if (k) {
                    f[i][j][k] += (double)k / (double)tot * (f[i][j + 1][k - 1]);
                }
                f[i][j][k] += (double)n / (double)tot;
            }
        }
    }

    cout << fixed << setprecision(12) << f[mp[1]][mp[2]][mp[3]];
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