#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    V<V<int>> f(m + 2, V<int>(n + 2, 0));

    V<int> ans;

    f[0][x - 1] = 1;

    FOR(i, 1, m) {
        int x;
        char c;
        cin >> x >> c;
        FOR(j, 0, n - 1) {
            if (c == '?' || c == '1') {
                f[i][((j - x) % n + n) % n] |= f[i - 1][j];
            }
            if (c == '?' || c == '0') {
                f[i][(j + x) % n] |= f[i - 1][j];
            }
        }
    }

    FOR(i, 0, n - 1) {
        if (f[m][i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
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
