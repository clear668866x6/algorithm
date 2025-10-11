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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    V<V<int>> g(n + 1);
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
    }

    V<V<int>> f(2 * k + 2, V<int>(n + 1, 0));

    FOR(i, 1, n) {
        if (s[i] == 'A') {
            f[2 * k][i] = 1;
        }
    }

    FORD(i, 0, k * 2 - 1) {
        FOR(u, 1, n) {
            if (!(i & 1)) {
                int t = 0;
                for (auto j : g[u]) {
                    if (f[i + 1][j]) {
                        t = 1;
                    }
                }
                f[i][u] = t;
            } else {
                int t = 1;
                for (auto j : g[u]) {
                    if (!f[i + 1][j]) {
                        t = 0;
                    }
                }
                f[i][u] = t;
            }
        }
    }

    if (f[0][1]) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
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
