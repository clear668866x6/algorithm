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
    int n;
    cin >> n;
    V<array<int, 3>> w(n + 1);
    FOR(i, 1, n) cin >> w[i][0] >> w[i][1] >> w[i][2];

    FOR(x, 0, 100) {
        FOR(y, 0, 100) {
            FOR(i, 1, n) {
                int h = w[i][2] + abs(x - w[i][0]) + abs(y - w[i][1]);
                if (h <= 0) continue;
                bool f = false;
                FOR(j, 1, n) {
                    if (w[j][2] != max<int>(0, h - abs(x - w[j][0]) - abs(y - w[j][1]))) {
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    cout << x << ' ' << y << ' ' << h << endl;
                    RE;
                }
            }
        }
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