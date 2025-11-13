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
    string s;
    cin >> s;
    int n = sz(s);
    s = ' ' + s;

    V<int> pre(n + 1, 0);
    FOR(i, 1, n) {
        int t = 0;
        if (s[i] == '1')
            t = 1;
        else
            t = -1;
        pre[i] = pre[i - 1] + t;
    }

    map<int, V<int>> mp;
    FOR(i, 1, n) {
        mp[pre[i]].push_back(i);
    }

    map<int, V<int>> suf;

    for (auto [x, y] : mp) {
        int t = sz(y);
        suf[x].resize(t + 2, 0);
        FORD(i, 1, t) {
            suf[x][i] = suf[x][i + 1] + y[i - 1];
        }
    }

    int ans = 0, mod = 1e9 + 7;

    FOR(i, 1, n) {
        int cnt = 0;
        auto it = upper_bound(ALL(mp[pre[i - 1]]), i);
        if (it != mp[pre[i - 1]].end()) {
            int len = it - mp[pre[i - 1]].begin();
            int del = sz(mp[pre[i - 1]]) - len;
            ans += (del * (n + 1) - suf[pre[i - 1]][len + 1]) * i % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    while (Task--) {
        solve();
    }

    return 0;
}
