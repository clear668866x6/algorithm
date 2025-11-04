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
    int g = 0;
    FOR(i, 1, n) cin >> w[i], g = gcd(g, w[i]);

    FOR(i, 1, n) w[i] /= g;

    int mx = *max_element(ALL(w));

    // V<V<int>> fac(mx + 1);
    V<int> fac(mx + 1);
    iota(ALL(fac), 0ll);

    FOR(i, 2, mx) {
        if (i == fac[i]) {
            FOR2(j, i, mx, i) {
                fac[j] = i;
            }
        }
    }

    // FOR(i, 2, mx) {
    //     if (fac[i].empty()) {
    //         FOR2(j, i, mx, i) {
    //             fac[j].eb(i);
    //         }
    //     }
    // }
    map<int, int> mp;
    FOR(i, 1, n) {
        int t = w[i];
        while (t > 1) {
            int p = fac[t];
            if (mp[p]) {
                NO;
                RE;
            }
            mp[p]++;
            while (t % p == 0) t /= p;
        }
    }
    YES;
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