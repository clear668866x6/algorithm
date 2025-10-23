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
    int n, k;
    cin >> n >> k;

    V<array<int, 3>> w(n);

    FOR(i, 0, n - 1) cin >> w[i][0] >> w[i][1] >> w[i][2];

    set<array<int, 2>> s;

    int tot = 0, mx = 0;

    FOR(i, 0, n - 1) {
        if (tot + w[i][2] <= k) {
            tot += w[i][2];
            if (w[i][0] >= mx) {
                cout << w[i][0] << endl;
                s.insert({w[i][0] + w[i][1], i});

            } else {
                cout << mx << endl;
                s.insert({mx + w[i][1], i});
            }
        } else {
            while (sz(s) && tot + w[i][2] > k) {
                tot -= w[(*s.begin())[1]][2];
                mx = max(mx, (*s.begin())[0]);
                s.erase(*s.begin());
            }
            if (w[i][0] >= mx) {
                cout << w[i][0] << endl;
                s.insert({w[i][0] + w[i][1], i});
            } else {
                cout << mx << endl;
                s.insert({mx + w[i][1], i});
            }
            tot += w[i][2];
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