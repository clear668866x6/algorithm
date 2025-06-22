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

    multiset<int>row, col;

    V<PII>w;

    FOR (i, 1, n) {
        int x, y;
        cin >> x >> y;
        row.insert (x);
        col.insert (y);
        w.eb (x, y);
    }

    if (n == 1) {
        cout << 1 << endl;
        RE;
    }

    int ans = (*row.rbegin () - *row.begin () + 1) * (*col.rbegin () - *col.begin () + 1);

    FOR (i, 1, n) {
        auto [x, y] = w[i - 1];
        row.erase (row.find (x));
        col.erase (col.find (y));
        int t = (*row.rbegin () - *row.begin () + 1) * (*col.rbegin () - *col.begin () + 1);
        if (t >= n) {
            ans = min (ans, t);
        } else {
            ans = min ({ ans,(*row.rbegin () - *row.begin () + 1) * (*col.rbegin () - *col.begin () + 2)
            ,(*row.rbegin () - *row.begin () + 2) * (*col.rbegin () - *col.begin () + 1) });
        }
        row.insert (x), col.insert (y);
    }
    cout << ans << endl;

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