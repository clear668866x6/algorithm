#include <bits/stdc++.h>
#include <numeric>
#include <queue>
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
    int n, m;
    cin >> n >> m;
    V<int> a(n + m + 2, 0), b(n + m + 2, 0);
    FOR(i, 1, n + m + 1) cin >> a[i];
    FOR(i, 1, n + m + 1) cin >> b[i];

    V<V<int>> pos(2);

    FOR(i, 1, n + m + 1) {
        pos[a[i] > b[i]].eb(i);
    }

    int sa = accumulate(ALL(a), 0LL), sb = accumulate(ALL(b), 0ll);
    V<int> vis(n + m + 2, 0);

    if (sz(pos[1]) > n) {
        int s1 = 0, s2 = 0;
        FOR(i, 0, n - 1) {
            s1 += a[pos[1][i]];
            s2 += b[pos[1][i]];
            vis[pos[1][i]] = 1;
        }

        FOR(i, 1, n + m + 1) {
            if (!vis[i]) {
                cout << (s1 + sb - s2 - b[i]) << ' ';
            } else {
                cout << (s1 - a[i] + sb - s2 - b[pos[1][n]] + a[pos[1][n]]) << ' ';
            }
        }
        cout << endl;
    } else {
        int s1 = 0, s2 = 0;
        FOR(i, 0, m - 1) {
            s1 += a[pos[0][i]];
            s2 += b[pos[0][i]];
            vis[pos[0][i]] = 1;
        }

        FOR(i, 1, n + m + 1) {
            if (!vis[i]) {
                cout << (s2 + sa - s1 - a[i]) << ' ';
            } else {
                cout << (s2 - b[i] + sa - s1 - a[pos[0][m]] + b[pos[0][m]]) << ' ';
            }
        }
        cout << endl;
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
