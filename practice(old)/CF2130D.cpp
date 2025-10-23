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

    V<int> w(n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int tot = 0;

    V<int> cnt(n + 1, 0);

    FOR(i, 1, n) {
        int t = 0;
        FOR(j, 1, i - 1) {
            if (w[j] > w[i]) {
                tot++;
                t++;
            }
        }
        cnt[i] = t;
    }
    // FOR(i, 1, n) cout << cnt[i] << ' ';
    // cout << tot << endl;

    FORD(i, 1, n) {
        int lst = tot;
        tot -= cnt[i];
        int p = 0;
        FOR(j, i + 1, n) {
            if (w[i] > w[j]) {
                tot--;
            }
            if ((2 * n - w[i]) > w[j]) {
                p++;
            }
        }
        tot += p;

        if (tot > lst) {
            tot = lst;
        } else {
            w[i] = 2 * n - w[i];
        }
    }

    // FOR(i, 1, n) cout << w[i] << ' ';

    cout << tot << endl;
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
