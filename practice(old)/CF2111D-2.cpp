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
    int n, m;
    cin >> n >> m;

    V<PII>w;

    FOR (i, 1, m) {
        int x;
        cin >> x;
        w.eb (x / 100, x);
    }

    sort (ALL (w));

    int l = 0, r = w.sz - 1;

    FOR2 (i, 0, n - 1, 2) {
        int x = w[l].se, y = w[r].se;
        FOR2 (j, 0, 5, 2) {
            cout << x << ' ' << y << ' ';
        }

        cout << endl;

        if (i + 1 < n) {
            FOR2 (j, 0, 5, 2) {
                cout << y << ' ' << x << ' ';
            }
        }
        cout << endl;
        l++, r--;
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