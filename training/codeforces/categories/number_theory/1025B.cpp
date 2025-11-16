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
    V<array<int, 2>> w(n + 1, {0, 0});
    FOR(i, 1, n) cin >> w[i][0] >> w[i][1];

    sort(ALL(w));
    w.erase(unique(ALL(w)), w.end());
    n = sz(w) - 1;

    auto calc = [&](int t) {
        set<int> c;
        FOR(i, 2, t / i) {
            if (t % i == 0) {
                c.insert(i);
                c.insert(t / i);
            }
        }

        c.insert(t);

        for (auto x : c) {
            bool f = 0;
            FOR(i, 2, n) {
                if (!(w[i][0] % x == 0 || w[i][1] % x == 0)) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                return x;
            }
        }
        return (int)-1;
    };

    int t1 = calc(w[1][0]), t2 = calc(w[1][1]);

    if (t1 == -1 && t2 == -1) {
        cout << -1 << endl;
    } else {
        cout << max(t1, t2) << endl;
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