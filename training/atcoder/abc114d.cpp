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

    map<int, int> mp;

    FOR(i, 2, n) {
        int t = i;
        FOR(j, 2, t / j) {
            if (t % j == 0) {
                while (t % j == 0) t /= j, mp[j]++;
            }
        }
        if (t > 1) mp[t]++;
    }

    int ans = 0;
    int c3 = 0, c5 = 0, c15 = 0, c25 = 0, c75 = 0;

    for (auto [x, y] : mp) {
        if (y >= 2) c3++;
        if (y >= 4) c5++;
        if (y >= 14) c15++;
        if (y >= 24) c25++;
        if (y >= 74) c75++;
    }

    ans += (c75);
    ans += (c3 * c25 - c25);
    ans += (c5 * c15 - c15);
    ans += (c3 * (c5 - 1) * c5 / 2 - (c5 - 1) * c5 / 2 - (c5 - 1) * c5 / 2);

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