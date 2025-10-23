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
    V<char> s1(n + 1, 0), s2(n + 1, 0);
    V<int> a(n + 1, 0), b(n + 1, 0);
    FOR(i, 1, n) cin >> s1[i], a[i] = (s1[i] == 'A');
    FOR(i, 1, n) cin >> s2[i], b[i] = (s2[i] == 'A');

    V<V<int>> f(n + 2, V<int>(5, 0));

    FOR(i, 2, n + 1) {
        if (i >= 4) {
            f[i][1] = max(f[i][1],
                          f[i - 3][1] + ((a[i] + a[i - 1] + a[i - 2]) >= 2) + ((b[i - 1] + b[i - 2] + b[i - 3]) >= 2));
            f[i][2] = max(f[i][2], f[i - 3][2] +
                                       ((a[i - 1] + a[i - 2] + a[i - 3] >= 2) + (b[i - 1] + b[i - 2] + b[i - 3] >= 2)));
            f[i][3] =
                max(f[i][3], f[i - 3][3] + ((a[i - 1] + a[i - 2] + a[i - 3] >= 2) + (b[i] + b[i - 1] + b[i - 2] >= 2)));
        }
        if (i >= 3) {
            f[i][2] = max(f[i][2], f[i - 2][3] + (a[i - 2] + a[i - 1] + b[i - 1] >= 2));
            f[i][2] = max(f[i][2], f[i - 2][1] + (b[i - 2] + b[i - 1] + a[i - 1] >= 2));
        }
        f[i][1] = max(f[i][1], f[i - 1][2] + ((a[i] + a[i - 1] + b[i - 1] >= 2)));
        f[i][3] = max(f[i][3], f[i - 1][2] + ((a[i - 1] + b[i] + b[i - 1] >= 2)));
    }
    cout << f[n + 1][2] << endl;
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
