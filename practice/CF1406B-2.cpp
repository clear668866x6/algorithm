#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
#define RE return;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz size()

void solve () {
    int n;
    cin >> n;

    V<int>w (n);
    for (auto& x : w)cin >> x;

    sort (ALL (w));

    V<int>a, b;
    bool f = false;

    for (auto x : w) {
        if (x > 0) {
            a.eb (x);
        } else {
            if (!x) {
                f = 1;
            }
            b.eb (x);
        }
    }

    if (!a.sz) {
        if (f) {
            cout << 0 << endl;
        } else {
            cout << w[n - 1] * w[n - 2] * w[n - 3] * w[n - 4] * w[n - 5] << endl;
        }
    } else {
        int ans = -1e18;

        FOR (i, 0, 5) {
            if (i & 1) {
                if (a.sz < i)continue;
                int p = 5 - i;
                if (b.sz < p)continue;
                int t = 1;

                FOR (j, 0, p - 1)t *= b[j];
                FOR (j, a.sz - i, a.sz - 1)t *= a[j];
                ans = max (ans, t);
            } else {
                if (a.sz < i)continue;
                int p = 5 - i;
                if (b.sz < p)continue;
                int t = 1;

                FOR (j, b.sz - p, b.sz - 1)t *= b[j];
                FOR (j, a.sz - i, a.sz - 1)t *= a[j];
                ans = max (ans, t);
            }
        }
        cout << ans << endl;
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}