#include <bits/stdc++.h>
#include <sstream>
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

    V<int> mp(1e5 + 10, 0);

    FOR(i, 1, n) {
        string s1, s2;
        cin >> s1 >> s2;
        stringstream ss, ss2;
        ss << s1;
        int h1, m1, se1, h2, m2, se2;
        char c;
        ss >> h1 >> c >> m1 >> c >> se1;
        ss2 << s2;
        ss2 >> h2 >> c >> m2 >> c >> se2;

        int t1 = h1 * 3600 + m1 * 60 + se1;
        int t2 = h2 * 3600 + m2 * 60 + se2;

        mp[t1]++, mp[t2 + 1]--;
    }

    FOR(i, 1, 1e5) mp[i] += mp[i - 1];

    int ans = 0;

    FOR(i, 1, 1e5) ans = max(ans, mp[i]);

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