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
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    s = ' ' + s, t = ' ' + t;

    V<V<int>> f(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            f[i][j] = max({f[i][j], f[i - 1][j], f[i][j - 1]});
            if (s[i] == t[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    string ans;

    int tot = f[n][m];

    FORD(i, 1, n) {
        FORD(j, 1, m) {
            if (s[i] == t[j] && f[i][j] == tot) {
                ans += s[i];
                tot--;
                break;
            }
        }
    }
    reverse(ALL(ans));

    cout << ans << endl;
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