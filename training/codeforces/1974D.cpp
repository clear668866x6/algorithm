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

    map<char, int> mp;

    FOR(i, 1, n) {
        mp[s[i]]++;
    }

    int a = 0;
    map<char, int> cr, cp;
    a = min(mp['N'], mp['S']);
    bool f = false;
    if (a) {
        if (mp['N'] > mp['S']) {
            cr['S'] += 1;
            cr['N'] += 1;
        } else {
            cr['S'] += 1;
            cr['N'] += 1;
        }
        f = 1;
    }
    mp['N'] -= a, mp['S'] -= a;

    a = min(mp['W'], mp['E']);
    if (a && !f) {
        if (mp['W'] > mp['E']) {
            cr['E'] += 1;
            cr['W'] += 1;
        } else {
            cr['E'] += 1;
            cr['W'] += 1;
        }
    }
    mp['W'] -= a, mp['E'] -= a;

    string p = "NSEW";

    FOR(i, 0, 3) {
        if (mp[p[i]]) {
            if (mp[p[i]] & 1) {
                NO;
                RE;
            }
            cr[p[i]] += mp[p[i]] / 2;
        }
    }

    int tot = 0;
    for (auto [x, y] : cr) tot += y;
    if (tot == n) {
        NO;
        RE;
    }

    FOR(i, 1, n) {
        if (cr[s[i]]) {
            cr[s[i]]--;
            cout << "R";
        } else {
            cout << "H";
        }
    }
    cout << endl;
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
