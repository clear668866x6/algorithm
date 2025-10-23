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
    int n, h, m, q;
    cin >> n >> h >> m >> q;
    V<int>w1, w2;
    FOR (i, 1, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        w1.eb (a * m + b);
        w2.eb (c * m + d);
    }
    sort (ALL (w1));
    sort (ALL (w2));

    while (q--) {
        int a, b;
        cin >> a >> b;
        int t = a * m + b;
        int l = lower_bound (ALL (w1), t) - w1.begin ();
        int r = lower_bound (ALL (w2), t) - w2.begin ();
        if (l == r) {
            Yes;
        } else {
            No;
        }
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}