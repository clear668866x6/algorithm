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

    int t = (1ll << n);

    V<int> w(t, 0);
    // iota(ALL(w), 0ll);
    FOR(i, 1, t) cin >> w[i];
    int tot = 0;
    FOR(i, 1, t - 1) {
        tot += (w[i] ^ w[i - 1]);
    }
    cout << tot << endl;
    V<int> c(1, 0);
    FOR(i, 0, t - 1) c.eb(i ^ (i / 2));

    tot = 0;
    FOR(i, 1, t - 1) {
        tot += (c[i] ^ c[i - 1]);
    }
    cout << tot << endl;

    // do {
    //     int tot = 0;
    //     FOR(i, 1, t - 1) {
    //         tot += (w[i] ^ w[i - 1]);
    //     }
    //     if (ans > tot) {
    //         ans = tot;
    //         res = w;
    //     }
    // } while (next_permutation(ALL(w)));

    // do {
    //     int tot = 0;
    //     FOR(i, 1, t - 1) {
    //         tot += (c[i] ^ c[i - 1]);
    //     }
    //     if (ans == tot) {
    //         for (auto x : c) cout << x << ' ';
    //         cout << endl;
    //     }
    // } while (next_permutation(ALL(c)));
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