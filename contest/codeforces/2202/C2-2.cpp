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

    int rt = w[1];
    V<array<int, 2>> c(1, {1, w[1]});

    FOR(i, 2, n) {
        if (w[i] > w[i - 1] + 1 || w[i] <= rt) {
            rt = w[i];
            c.pb({i, w[i]});
        }
    }
    c.pb({0, 0});
    c.pb({n + 1, 10000});

    sort(ALL(c));

    for (auto [x, y] : c) {
        cout << y << ' ';
    }
    int ans = 0;

    FOR(l, 1, sz(c) - 2) {
        FOR(r, l, sz(c) - 2) {
            ans += (r - l + 1) * (c[r + 1][0] - c[r][0]) * (c[l][0] - c[l - 1][0]);
        }
    }

    // for (auto [x, y] : c) {
    //     ans += y * (n - y + 1);
    // }
    cout << ans << endl;
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