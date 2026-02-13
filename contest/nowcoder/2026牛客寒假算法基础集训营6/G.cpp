#include <algorithm>
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
    int n, m, L;
    cin >> n >> m >> L;
    V<int> x(n + 1, 0), y(m + 1, 0);
    FOR(i, 1, n) cin >> x[i];
    FOR(i, 1, m) cin >> y[i];

    int tot = 0;
    V<int> s;
    FOR(i, 1, n) {
        tot += x[i];
        s.eb(tot);
    }

    int st = 0;
    FOR(i, 0, m) {
        st += y[i];
        int l = st, r = st + L;
        int del = lower_bound(ALL(s), r) - upper_bound(ALL(s), l);
        if (del) {
            YES;
            RE;
        }
    }
    NO;
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