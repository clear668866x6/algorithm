#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
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
//此时可能会出现一个问题，就是如果你计算相邻的来算总的方案，此时我们可以转化成线段相交的问题。
/*
--
  --
    --
----
  ----
------

*/

void solve() {
    int n;
    cin >> n;
    V<int>w(n);
    for (auto& x : w)cin >> x;

    map<int, V<int>>mp;

    FOR(i, 1, n){
        mp[w[i - 1]].eb(i);
    }

    int ans = 0;

    for (auto [x, y] : mp){
        FOR(i, 1, y.sz - 1){
            ans += (y[i] - y[i - 1] - 1) * i * (y.sz - i);
        }
    }
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