#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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

    V<array<int, 2>> w(n);

    FOR(i, 0, n - 1) {
        cin >> w[i][0];
        w[i][1] = i + 1;
    }

    sort(RALL(w));

    int r = 1, t = 1;

    map<int, int> mp;
    mp[w[0][1]] = 1;
    FOR(i, 1, n - 1) {
        r++;
        if (w[i][0] != w[i - 1][0]) {
            t = r;
        }
        mp[w[i][1]] = t;
    }

    FOR(i, 1, n) cout << mp[i] << endl;
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
