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

    if (n == 1) {
        if (m == 1) {
            cout << 0 << endl << 0 << endl;
        } else {
            cout << 2 << endl;
            FOR (i, 0, m - 1)cout << i << " \n"[i == m - 1];
        }
        RE;
    }

    V<V<int>>w (n + 1, V<int> (m + 1, 0));

    FOR (i, 1, min (n, m)) {
        int k = 0;
        FOR (j, i + 1, m) {
            w[i][j] = k++;
        }
        k = m - 1;
        FORD (j, 1, i)w[i][j] = k--;
    }

    if (n >= m) {
        FOR (i, m, n) {
            FOR (j, 1, m) {
                w[i][j] = w[i - 1][j];
            }
        }
    }

    if (m == 1) {
        cout << 0 << endl;
    } else {
        cout << min (n, m - 1) + 1 << endl;
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cout << w[i][j] << ' ';
        }
        cout << endl;
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