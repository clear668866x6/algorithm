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
    int x, y;
    cin >> x >> y;

    if (x == y) {
        cout << -1 << endl;
        RE;
    }

    int ans = 0;

    if (x > y) swap(x, y);

    int len = 0;
    int t = y;
    while (t) {
        len++;
        t /= 2;
    }

    if (x + y == (x ^ y)) {
        cout << 0 << endl;
        RE;
    }

    FOR(i, 0, 62) {
        if (!(y >> i & 1)) {
            int t = ((y >> i) | 1) << i;
            int del = abs(t - y);
            if (x + y + 2 * del == ((x + del) ^ (y + del))) {
                cout << del << endl;
                RE;
            }
        }
    }

    cout << -1 << endl;
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
