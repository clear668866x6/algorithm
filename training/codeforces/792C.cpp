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
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;

    V f(n + 1, V<int>(3, 1e18));
    V pre(n + 1, V<int>(3, 0));
    f[0][0] = 0;

    FOR(i, 1, n) {
        FOR(j, 0, 2) {
            f[i][j] = f[i - 1][j] + 1;
            pre[i][j] = j;
            int t = s[i] - '0';
            if (!t && f[i - 1][j] == i - 1) continue;
            if (f[i][j] > f[i - 1][((j - t) % 3 + 3) % 3]) {
                f[i][j] = f[i - 1][((j - t) % 3 + 3) % 3];
                pre[i][j] = ((j - t) % 3 + 3) % 3;
            }
        }
    }
    if (f[n][0] == n) {
        FOR(i, 1, n) {
            if (s[i] == '0') {
                cout << 0 << endl;
                RE;
            }
        }
        cout << -1 << endl;
        RE;
    }

    int p = 0;
    string ans;
    FORD(i, 1, n) {
        int t = p;
        p = pre[i][t];
        if (f[i][t] == f[i - 1][p]) ans += s[i];
    }

    while (sz(ans) > 1 && ans.back() == '0') ans.pop_back();
    reverse(ALL(ans));
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