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

int n;
set<int> c;
V<int> d;

void dfs(int u, string p) {
    if (sz(p) > 9) RE;
    if (sz(p) <= 9 && sz(p) >= 1) {
        int t = 0;
        for (auto x : p) t = t * 10 + (x - '0');
        if (!t) RE;
        c.insert(t);
    }
    if (u > 9) {
        RE;
    }

    FOR(i, 0, sz(d) - 1) {
        string t = to_string(d[i]);
        if (sz(t) + sz(p) > 9) break;
        FOR(j, 0, sz(t) - 1) {
            p += t[j];
        }
        dfs(u + 1, p);
        int tp = sz(t);
        while (tp--) p.pop_back();
    }
}

void solve() {
    FOR(i, 0, 32) {
        d.eb((1ll << i));
    }

    dfs(0, "");

    int n;
    cin >> n;

    int cnt = 0;

    for (auto x : c) {
        cnt++;
        if (cnt == n) {
            cout << x << endl;
            RE;
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