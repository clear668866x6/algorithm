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
    int n, m;
    cin >> n >> m;
    string s;
    map<string, array<int, 3>> mp;
    map<string, int> mp2;
    FOR(i, 1, n) {
        string s;
        cin >> s;
        s = ' ' + s;

        FOR(j, 1, m - 1) {
            string p = s.substr(j, 2);
            mp[p] = {j, j + 1, i};
            mp2[p]++;
        }
        FOR(j, 1, m - 2) {
            string p = s.substr(j, 3);
            mp[p] = {j, j + 2, i};
            mp2[p]++;
        }
    }
    cin >> s;

    s = ' ' + s;

    V<array<int, 3>> ans;

    V<int> f(m + 2, 0);
    f[0] = 1;
    FOR(i, 1, m) {
        if (i - 3 >= 0 && mp2[s.substr(i - 2, 3)]) {
            f[i] |= f[i - 3];
        }
        if (i - 2 >= 0 && mp2[s.substr(i - 1, 2)]) {
            f[i] |= f[i - 2];
        }
    }

    if (f[m]) {
        for (int i = m; i;) {
            if (i >= 2 && f[i] == f[i - 2]) {
                auto [l, r, idx] = mp[s.substr(i - 1, 2)];
                ans.pb({l, r, idx});
                i -= 2;
            } else if (i >= 3 && f[i] == f[i - 3]) {
                auto [l, r, idx] = mp[s.substr(i - 2, 3)];

                ans.pb({l, r, idx});
                i -= 3;
            } else
                break;
        }
        reverse(ALL(ans));
        cout << sz(ans) << endl;
        for (auto [l, r, i] : ans) cout << l << ' ' << r << ' ' << i << endl;

    } else {
        cout << -1 << endl;
    }
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
