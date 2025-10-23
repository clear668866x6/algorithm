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
    int n, h, m;
    cin >> n >> h >> m;

    V<int>A (n + 1, 0), B (n + 1, 0);

    FOR (i, 1, n) {
        cin >> A[i] >> B[i];
    }

    V<V<int>>f (n + 1, V<int> (h + 1, 1e18));
    f[0][0] = 0;
    int ans = 0;

    FOR (i, 1, n) {
        FOR (j, 0, h) {
            f[i][j] = min (f[i - 1][j] + B[i], f[i][j]);
            if (j >= A[i]) {
                f[i][j] = min (f[i][j], f[i - 1][j - A[i]]);
            }
        }
    }

    FORD (i, 1, n) {
        FOR (j, 1, h) {
            if (f[i][j] <= m) {
                cout << i << endl;
                RE;
            }
        }
    }

    cout << 0 << endl;

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