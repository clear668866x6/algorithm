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

    V<int> vis(n + 1, 0);
    if (n & 1) {
        vis[n] = vis[n - 1] = vis[1] = vis[3] = 1;
        cout << n << endl;
        int idx = 1;
        FOR(i, 1, n - 4) {
            while (vis[idx]) idx++;
            vis[idx] = 1;
            cout << idx << ' ';
        }

        cout << "3 1 " << n - 1 << ' ' << n << endl;

    } else {

        if (n == 6) {
            cout << 7 << endl << "1 2 4 6 5 3" << endl;
            RE;
        }
        int len = 0, t = n;
        while (t) {
            len++;
            t /= 2;
        }

        cout << (1ll << len) - 1 << endl;
        int p = (1ll << (len - 1));
        vis[p] = vis[p - 1] = vis[p - 2] = vis[3] = vis[1] = 1;

        int idx = 1;
        FOR(i, 1, n - 5) {
            while (vis[idx]) idx++;
            vis[idx] = 1;
            cout << idx << ' ';
        }

        cout << "3 1 " << p - 2 << ' ' << p - 1 << ' ' << p << endl;
    }
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
