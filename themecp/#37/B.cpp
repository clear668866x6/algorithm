#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
    cin >> n;

    if (n == 1) {
        cout << "a" << endl;
        RE;
    }

    int mx = 0;

    V<int> w;

    FOR(i, 2, n / i) {
        if (n % i == 0) {
            w.eb(i);
            w.eb(n / i);
        }
    }

    sort(ALL(w));

    if (!sz(w)) {
        FOR2(i, 1, n / 2 * 2, 2) cout << "ab";
        if (n & 1)
            cout << "a";
        cout << endl;
        RE;
    }

    bool f = false;

    FOR(i, 1, 26) {
        if (n % i) {
            int t = i;
            FOR2(j, 1, n / t * t, t) {
                FOR(k, 'a', 'a' + t - 1) { cout << char(k); }
            }
            int p = n - n / t * t;
            FOR(j, 'a', 'a' + p - 1) cout << char(j);
            cout << endl;
            f = 1;
            break;
        }
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
