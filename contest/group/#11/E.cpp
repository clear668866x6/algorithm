#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
    cin >> n;

    function<int(int)> check = [&](int u) {
        while (u) {
            if (u % 3 == 2) {
                return 0;
            }
            u /= 3;
        }
        return 1;
    };

    if (check(n)) {
        cout << n << endl;
        RE;
    }

    string s;

    int p = n;
    while (p) {
        s += ('0' + p % 3);
        p /= 3;
    }

    reverse(ALL(s));

    string t;
    int res = (1LL << 62);
    int m = sz(s);
    function<int(string)> ck = [&](string s) {
        int t = 0;
        for (auto x : s) {
            if (x == '2') return (int)0;
            t = t * 3 + (x - '0');
        }
        if (t >= n) return t;
        return (int)0;
    };

    FOR(i, 0, m - 1) {
        t += '0';
        s.pop_back();
        if (sz(s) && s.back() == '0') s[sz(s) - 1] = '1';
        string ans = (s + t);
        if (ck(ans)) {
            res = min(res, ck(ans));
        }
    }
    reverse(ALL(t));
    t.pb('1');
    reverse(ALL(t));
    if (ck(t)) {
        res = min(res, ck(t));
    }
    cout << res << endl;
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
