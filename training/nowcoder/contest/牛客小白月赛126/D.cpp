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
    int n, q;
    cin >> n >> q;

    V<int> b1(n + 10, 0), b2(n + 10, 0);
    V<V<int>> b3(n + 10, V<int>(4, 0));

    FOR(i, 1, n) {
        int a, b;
        cin >> a >> b;
        b1[a]++;
        b2[b]++;

        if (a > b) swap(a, b);
        if (b - a + 1 <= 3) {
            b3[a][b - a + 1]++;
        }
    }

    FOR(i, 1, n + 1) b1[i] += b1[i - 1], b2[i] += b2[i - 1];

    while (q--) {
        int x;
        cin >> x;
        int ans = b1[x + 1] - b1[max<int>(0, x - 2)] + b2[x + 1] - b2[max<int>(0, x - 2)];
        FOR(j, 1, 3) {
            ans -= (b3[x - 1][j]);
        }
        FOR(j, 1, 2) {
            ans -= b3[x][j];
        }
        FOR(j, 1, 1) {
            ans -= b3[x + 1][j];
        }
        cout << n - ans << ' ';
    }
    cout << endl;
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
