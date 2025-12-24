#include <bits/stdc++.h>
#include <numeric>
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
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s = ' ' + s;
    V<int> p(n + 1, 0);
    FOR(i, 1, n) cin >> p[i];

    int tot = accumulate(ALL(p), 0ll);

    if (tot > x + y) {
        NO;
        RE;
    }

    int c1 = 0, c2 = 0;
    int c3 = 0, c4 = 0;
    int cnt0 = 0, cnt1 = 0;

    FOR(i, 1, n) {
        if (s[i] == '0') {
            cnt0++;
            c1 += (p[i] / 2 + 1);
            if (p[i] % 2 == 0) c3++;
        } else {
            cnt1++;
            c2 += (p[i] / 2 + 1);
            if (p[i] % 2 == 0) c4++;
        }
    }

    if (c1 > x || c2 > y) {
        NO;
        RE;
    }

    int remain = (x + y - tot);

    int add1 = 0, add2 = 0;

    if (cnt0 > 0) {
        add1 += c3 + 2 * (x - c1);
    }

    if (cnt1 > 0) {
        add2 += c4 + 2 * (y - c2);
    }

    if (add1 + add2 >= remain) {
        YES;
    } else {
        NO;
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
