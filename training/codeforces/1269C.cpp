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
    string s;
    cin >> n >> s;
    s = ' ' + s;

    V<int> px(n + 1, 0), py(n + 1, 0);
    map<array<int, 2>, V<int>> mp;
    map<char, int> mp2;
    mp2['L'] = 1, mp2['R'] = -1, mp2['U'] = 2, mp2['D'] = -2;

    mp[{0, 0}].eb(0);
    FOR(i, 1, n) {
        if (s[i] == 'L' || s[i] == 'R') {
            px[i] = px[i - 1] + mp2[s[i]];
            py[i] = py[i - 1];
        } else {
            px[i] = px[i - 1];
            py[i] = py[i - 1] + mp2[s[i]];
        }
        mp[{px[i], py[i]}].eb(i);
    }

    int ans = 1e18, ansl = 0, ansr = 0;

    for (auto [x, y] : mp) {
        FOR(i, 1, sz(y) - 1) {
            if (y[i] - y[i - 1] < ans) {
                ans = y[i] - y[i - 1];
                ansl = y[i - 1] + 1, ansr = y[i];
            }
        }
    }

    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ansl << ' ' << ansr << endl;
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
