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

    V<int> pre2(n + 2, 0), fu(n + 2, 0);

    FOR(i, 1, n) {
        pre2[i] = pre2[i - 1] + (abs(w[i]) == 2);
        fu[i] = fu[i - 1] + (w[i] < 0);
    }
    pre2[n + 1] = pre2[n];
    fu[n + 1] = fu[n];

    V<int> x0(1, 0);

    FOR(i, 1, n) {
        if (!w[i]) {
            x0.eb(i);
        }
    }
    x0.eb(n + 1);

    int t = 0, tl = 0, tr = n;
    FOR(i, 1, sz(x0) - 1) {
        if ((fu[x0[i]] - fu[x0[i - 1]]) & 1) {
            FOR(j, x0[i - 1] + 1, x0[i] - 1) {
                if (!((fu[j - 1] - fu[x0[i - 1]]) & 1)) {
                    if (pre2[j - 1] - pre2[x0[i - 1]] > t) {
                        t = pre2[j - 1] - pre2[x0[i - 1]];
                        tl = x0[i - 1], tr = (n - j + 1);
                    }
                }
                if (!((fu[x0[i] - 1] - fu[j]) & 1)) {
                    if (pre2[x0[i]] - pre2[j] > t) {
                        t = pre2[x0[i]] - pre2[j];
                        tl = j, tr = (n - x0[i] + 1);
                    }
                }
            }
        } else {
            if (pre2[x0[i]] - pre2[x0[i - 1]] > t) {
                t = pre2[x0[i]] - pre2[x0[i - 1]];
                tl = x0[i - 1], tr = (n - x0[i] + 1);
            }
        }
    }
    cout << tl << ' ' << tr << endl;
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
