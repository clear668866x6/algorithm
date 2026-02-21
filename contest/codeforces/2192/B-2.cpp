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

bool check(string s) {
    for (auto x : s) {
        if (x == '1') {
            return 0;
        }
    }
    return 1;
}
V<int> c;
int n;
string s;
int vis[100];

void dfs(int u, string ans) {
    if (u > n) RE;
    if (check(ans)) {
        for (auto x : c) {
            cout << x << ' ';
        }
        cout << endl;
        RE;
    }

    FOR(i, 0, n - 1) {
        if (vis[i]) continue;
        vis[i] = 1;
        string p = ans;
        FOR(j, 0, n - 1) {
            if (i == j) continue;
            if (ans[j] == '1')
                p[j] = '0';
            else
                p[j] = '1';
        }
        c.eb(i + 1);
        dfs(u + 1, p);
        vis[i] = 0;
        c.pop_back();
    }
}

void solve() {
    cin >> n >> s;

    dfs(1, s);
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