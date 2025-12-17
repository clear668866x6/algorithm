#include <bits/stdc++.h>
#include <numeric>
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
    V<int> b(n + 3, 0);
    FOR(i, 1, n + 2) cin >> b[i];

    ranges::sort(b);

    int t = b[n + 2], tot = accumulate(ALL(b), 0ll);
    tot -= t;

    FOR(i, 1, n + 1) {
        if (tot - b[i] == t) {
            FOR(j, 1, i - 1) cout << b[j] << ' ';
            FOR(j, i + 1, n + 1) cout << b[j] << ' ';
            cout << endl;
            RE;
        }
    }

    tot = accumulate(ALL(b), 0ll);
    t = b[n + 1];
    tot -= t;

    FOR(i, 1, n + 2) {
        if (i == n + 1) {
            continue;
        }
        if (tot - b[i] == b[n + 1]) {
            FOR(j, 1, i - 1) {
                if (j == n + 1) {
                    continue;
                }
                cout << b[j] << ' ';
            }
            FOR(j, i + 1, n + 2) {
                if (j == n + 1) continue;
                cout << b[j] << ' ';
            }
            cout << endl;
            RE;
        }
    }

    cout << -1 << endl;
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
