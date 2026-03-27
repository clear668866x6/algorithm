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
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    map<int, int> mp;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;

    if (n == 1) {
        cout << 1 << endl;
        RE;
    }
    if (mp[w[1]] == n || n == 2) {
        cout << 2 << endl;
        RE;
    }

    int mx = *max_element(ALL(w)), mn = *min_element(w.begin() + 1, w.end());

    int ans = 2, c1 = 0, c2 = 0;

    FOR(i, 2, n - 1) {
        if (w[i] == mn) {
            c1 = 1;
        } else if (w[i] == mx) {
            c2 = 1;
        }
    }

    if (w[1] == mn || w[n] == mn) c1 = 0;
    if (w[1] == mx || w[n] == mx) c2 = 0;

    ans += (c1 + c2);
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