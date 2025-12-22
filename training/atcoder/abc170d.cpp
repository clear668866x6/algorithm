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
    V<int> mp(1e6 + 10, 0);
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;

    V<V<int>> fac(1e6 + 1);

    FOR(i, 1, 1e6) fac[i].eb(1);

    FOR(i, 2, 1e6) {
        FOR2(j, i, 1e6, i) {
            fac[j].eb(i);
        }
    }

    int ans = 0;

    FOR(i, 1, n) {
        bool f = false;
        for (auto j : fac[w[i]]) {
            if (j == w[i]) {
                if (mp[j] > 1) {
                    f = 1;
                    break;
                }
            } else {
                if (mp[j]) {
                    f = 1;
                    break;
                }
            }
        }
        if (!f) ans++;
    }

    cout << ans;
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