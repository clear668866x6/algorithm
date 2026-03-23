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
    V<int> c(n + 1, 0), w(n + 1, 0);
    V<int> cnt(n + 1, 0);
    map<int, V<int>> mp;
    FOR(i, 1, n) cin >> c[i], cnt[c[i]]++, mp[c[i]].eb(i);
    FOR(i, 1, n) cin >> w[i];

    V<int> l(n + 1, n), r(n + 1, 1);
    V<int> d(n + 1, 0);

    for (auto [x, y] : mp) {
        if (!y.empty()) {
            d[x]++;
            FOR(j, 1, sz(y) - 1) {
                if (y[j] - y[j - 1] != 1) {
                    d[x]++;
                }
            }
        }
    }

    FOR(i, 1, n) {
        if (!cnt[i]) {
            cout << n + w[i] << ' ';
        } else {
            int ans = (n - cnt[i]) + w[i];

            auto &y = mp[i];
            int st = y[0];
            int cur = 1;

            FOR(j, 1, sz(y) - 1) {
                if (y[j] == y[j - 1] + 1) {
                    cur++;
                } else {
                    if (st != 1) {
                        ans += min(w[i], cur);
                    }
                    st = y[j];
                    cur = 1;
                }
            }

            if (st != 1 && y.back() != n) {
                ans += min(w[i], cur);
            }

            cout << ans << ' ';
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