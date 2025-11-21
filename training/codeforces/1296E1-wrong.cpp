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
    string s, t;
    cin >> n >> s;
    t = s;
    sort(ALL(t));
    t = ' ' + t;
    s = ' ' + s;
    map<char, set<int>> mp;
    FOR(i, 1, n) {
        mp[s[i]].insert(i);
    }

    V<int> ans(n + 1, -1), p(n + 1, 0);
    iota(ALL(p), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    map<int, set<int>> mp2;

    FOR(i, 1, n) {
        auto it = mp[t[i]].begin();
        int a = i, b = *it;
        int x = a, y = b;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            mp2[b].insert(x);
            mp2[b].insert(y);
        }
        mp[t[i]].erase(it);
    }

    for (auto [x, y] : mp2) {
        // cout << x << ' ' << sz(y) << endl;
        if (sz(y) & 1) {
            NO;
            RE;
        }

        int l = 0;
        for (auto t : y) {
            if (ans[t] != -1) {
                l ^= 1;
            } else {
                ans[t] = l;
                l ^= 1;
            }
        }
    }

    FOR(i, 1, n) {
        if (ans[i] == -1) ans[i] = 0;
    }

    YES;
    FOR(i, 1, n) cout << ans[i];
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