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

    V<V<char>> w(n + 1, V<char>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    V<array<int, 2>> ans(n);

    FOR(i, 0, n - 1) {
        ans[i] = {0, i + 1};
    }

    FOR(j, 1, m) {
        int c1 = 0, c0 = 0;
        FOR(i, 1, n) {
            c1 += (w[i][j] == '1');
            c0 += (w[i][j] == '0');
        }
        if (!c1 || !c0) {
            FOR(i, 1, n) {
                ans[i - 1][0]++;
            }
        } else if (c1 < c0) {
            FOR(i, 1, n) {
                if (w[i][j] == '1') {
                    ans[i - 1][0]++;
                }
            }
        } else {
            FOR(i, 1, n) {
                if (w[i][j] == '0') {
                    ans[i - 1][0]++;
                }
            }
        }
    }

    sort(RALL(ans));

    V<int> res;

    FOR(i, 0, n - 1) {
        if (ans[i][0] == ans[0][0]) {
            res.eb(ans[i][1]);
        }
    }

    sort(ALL(res));

    for (auto x : res) cout << x << ' ';
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