#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    string a, b;
    cin >> a >> b;
    map<char, int> mp;

    FOR(i, 0, b.sz - 2) { mp[b[i]] = i + 1; }
    int ans = 1e18, idx1 = 0, idx2 = 0;

    FOR(i, 1, a.sz - 1) {
        if (mp[a[i]]) {
            int t = i + 1 + (b.sz - mp[a[i]]);

            if (ans > t) {
                ans = t;
                idx1 = i;
                idx2 = mp[a[i]] - 1;
            }
        }
    }

    if (ans == 1e18) {
        cout << -1 << endl;
        RE;
    }

    cout << (a.substr(0, idx1) + b.substr(idx2)) << endl;
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
