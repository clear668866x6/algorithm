#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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

int rev(int x) {
    V<int> w;

    while (x) {
        w.eb(x & 1);
        x /= 2;
    }

    int ans = 0;
    for (auto x : w) ans = ans * 2 + x;

    return ans;
}

map<int, int> mp;

void dfs(int u, int v) {
    if (u == v) {
        YES;
        exit(0);
    }
    if (mp[u] || u > (v * 2)) RE;
    mp[u]++;
    dfs(rev(u), v);

    u = u * 2;
    u++;
    dfs(rev(u), v);
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        YES;
        RE;
    }

    dfs(a, b);
    dfs(rev(a), b);
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