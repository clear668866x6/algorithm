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
    int n;
    cin >> n;
    V<V<int>> w(n + 1, V<int>(n + 1, 0));

    w[0][(n - 1) / 2] = 1;

    int k = 2, tot = n * n - 1;

    int r = 0, c = (n - 1) / 2;

    while (tot--) {
        if (w[(r - 1 + n) % n][(c + 1) % n] == 0) {
            w[(r - 1 + n) % n][(c + 1) % n] = k++;
            r = (r - 1 + n) % n, c = (c + 1) % n;
        } else {
            w[(r + 1) % n][c] = k++;
            r = (r + 1) % n;
        }
    }

    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1) {
            cout << w[i][j] << " \n"[j == n - 1];
        }
    }
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}