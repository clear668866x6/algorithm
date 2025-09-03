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
    int n, m;
    cin >> n >> m;

    V<V<char>> s(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> s[i][j];
        }
    }

    V<V<int>> p1(n + 2, V<int>(m + 2, 0)), p2(n + 2, V<int>(m + 2, n + 1));
    V<V<int>> p3(n + 2, V<int>(m + 2, 0)), p4(n + 2, V<int>(m + 2, m + 1));

    FOR(j, 1, m) {
        FOR(i, 1, n) {
            if (s[i][j] == '#') {
                p1[i][j] = i;
            } else
                p1[i][j] = p1[i - 1][j];
        }
        FORD(i, 1, n) {
            if (s[i][j] == '#') {
                p2[i][j] = i;
            } else
                p2[i][j] = p2[i + 1][j];
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '#') {
                p3[i][j] = j;
            } else
                p3[i][j] = p3[i][j - 1];
        }
        FORD(j, 1, m) {
            if (s[i][j] == '#') {
                p4[i][j] = j;
            } else
                p4[i][j] = p4[i][j + 1];
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (s[i][j] == '.') {
                ans = max(ans, (p2[i][j] - p1[i][j] - 1) + (p4[i][j] - p3[i][j] - 1) - 1);
            }
        }
    }
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