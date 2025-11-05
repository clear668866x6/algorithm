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
    int n, k;
    cin >> n >> k;

    if (n * n < k) {
        cout << -1 << endl;
        RE;
    }

    V<V<int>> ans(n + 1, V<int>(n + 1, 0));

    if (k) {
        FOR(i, 1, n) {
            FOR(j, i, n) {
                if (i == j)
                    ans[i][i] = 1, k--;
                else
                    ans[i][j] = ans[j][i] = 1, k -= 2;
                if (!k) {
                    break;
                }
                if (k < 0) {
                    ans[i][j] = ans[j][i] = 0;
                    ans[i + 1][i + 1] = 1;
                    k = 0;
                }
            }
            if (!k) break;
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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