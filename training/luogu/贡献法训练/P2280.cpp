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

    V<V<int>> s(5010, V<int>(5010, 0));

    FOR(i, 1, n) {
        int x, y, v;
        cin >> x >> y >> v;
        s[x + 1][y + 1] += v;
    }

    FOR(i, 1, 5001) {
        FOR(j, 1, 5001) {
            s[i][j] += s[i - 1][j];
        }
    }

    FOR(i, 1, 5001) {
        FOR(j, 1, 5001) {
            s[i][j] += s[i][j - 1];
        }
    }

    int ans = 0;

    FOR(i, 1, 5001) {
        FOR(j, 1, 5001) {
            if (i - m >= 0 && j - m >= 0) {
                ans = max(ans, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
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