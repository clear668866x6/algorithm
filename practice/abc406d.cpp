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
    int h, w, n;
    cin >> h >> w >> n;

    map<int, multiset<int>>row, col;
    map<int, int>vis, vis2;

    FOR (i, 1, n) {
        int x, y;
        cin >> x >> y;
        row[x].insert (y);
        col[y].insert (x);
    }

    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            if (vis[x]) {
                cout << 0 << endl;
                continue;
            }
            cout << int (row[x].sz) << endl;
            for (auto y : row[x]) {
                col[y].erase (col[y].find (x));
            }
            vis[x] = 1;
        } else {
            if (vis2[x]) {
                cout << 0 << endl;
                continue;
            }
            cout << int (col[x].sz) << endl;
            for (auto y : col[x]) {
                row[y].erase (row[y].find (x));
            }
            vis2[x] = 1;
        }
    }
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}