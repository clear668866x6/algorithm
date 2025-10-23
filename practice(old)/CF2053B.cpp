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

    V<PII>w (n);
    V<int>b (n * 2 + 1, 0), b2 (n * 2 + 1, 0);
    V<int>c;
    for (auto& [x, y] : w)cin >> x >> y;

    for (auto [x, y] : w) {
        if (x == y) {
            b[x]++;
        }
    }

    for (auto [x, y] : w) {
        if (x == y && b[x] >= 2) {
            b2[x]++;
        }
        if (x == y && b[x] > 0) {
            c.eb (x);
        }
    }
    sort (ALL (c));
    c.erase (unique (ALL (c)), c.end ());

    for (auto [x, y] : w) {
        if (x == y) {
            if (b2[x]) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            int len = upper_bound (ALL (c), y) - lower_bound (ALL (c), x);
            if (y - x + 1 == len) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }

    cout << endl;
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