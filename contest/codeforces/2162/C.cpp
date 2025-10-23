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
    int a, b;
    cin >> a >> b;

    int len1 = 0, len2 = 0;
    int t1 = a, t2 = b;
    while (t1) {
        len1++;
        t1 /= 2;
    }

    while (t2) {
        len2++;
        t2 /= 2;
    }

    if (len1 < len2) {
        cout << -1 << endl;
        RE;
    }

    if (a == b) {
        cout << 0 << endl;
        RE;
    }

    int len = 0, t = a;
    V<int> c;
    while (t) {
        c.eb(t & 1);
        t /= 2;
    }

    int tmp1 = 0;
    FOR(i, 0, sz(c) - 1) {
        if (c[i] == 0) {
            tmp1 |= (1ll << i);
        }
    }

    cout << 2 << endl;
    cout << tmp1 << ' ' << (a ^ tmp1 ^ b) << endl;
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
