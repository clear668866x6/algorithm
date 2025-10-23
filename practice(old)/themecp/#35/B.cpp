#include <array>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n, m;
    cin >> n >> m;

    V<V<char>> w(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
            w[i][j] -= '0';
        }
    }

    int ans = 0;

    int x1 = 1, y1 = 1, x2 = n, y2 = m;

    while (1) {
        if (x1 > x2 || y1 > y2)
            break;

        V<int> num;

        FORD(i, x1, x2) num.eb(w[i][y1]);
        FOR(i, y1 + 1, y2 - 1) num.eb(w[x1][i]);
        FOR(i, x1, x2) num.eb(w[i][y2]);
        FORD(i, y1 + 1, y2 - 1) num.eb(w[x2][i]);

        FOR(i, 0, num.sz - 1) {
            if (num[i] == 1 && num[(i + 1) % num.sz] == 5 &&
                num[(i + 2) % num.sz] == 4 && num[(i + 3) % num.sz] == 3)
                ans++;
        }

        x1++, y1++, x2--, y2--;
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