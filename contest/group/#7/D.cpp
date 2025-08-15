#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
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
    string a, b;
    cin >> n >> a >> b;
    a = ' ' + a, b = ' ' + b;

    map<int, set<int>> mp;
    int c1 = 0, c2 = 0;

    FOR(i, 1, n) c1 += (a[i] == '?'), c2 += (b[i] == '?');

    FOR(i, 1, n) {
        mp[b[i]].insert(i);
    }

    V<array<int, 2>> ans;
    V<int> vis(n + 1, 0);

    FOR(i, 1, n) {
        if (vis[i]) continue;
        if (a[i] != '?') {
            if (sz(mp[a[i]])) {
                ans.pb({i, *mp[a[i]].begin()});
                mp[a[i]].erase(mp[a[i]].begin());
                vis[i] = 1;
            } else if (c2) {
                c2--;
                ans.pb({i, *mp['?'].begin()});
                mp['?'].erase(mp['?'].begin());
                vis[i] = 1;
            }
        }
    }

    FOR(i, 1, n) {
        if (vis[i]) continue;
        if (a[i] == '?') {
            bool f = false;
            FOR(c, 'a', 'z') {
                if (sz(mp[c])) {
                    ans.pb({i, *mp[c].begin()});
                    mp[c].erase(mp[c].begin());
                    c1--;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                ans.pb({i, *mp['?'].begin()});
                mp['?'].erase(mp['?'].begin());
                c2--, c1--;
            }
        }
    }

    cout << sz(ans) << endl;
    for (auto [a, b] : ans) cout << a << ' ' << b << endl;
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
