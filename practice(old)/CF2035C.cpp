#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
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
#define sz size()

void solve() {
    int n;
    cin >> n;

    if (n & 1) {
        cout << n << endl;
        if (n == 5) {
            cout << "2 1 3 4 5" << endl;
        } else {
            V<int> vis(n + 1, 0);

            vis[n - 4] = 1, vis[n - 2] = 1, vis[n - 1] = 1, vis[n] = 1;

            FOR(i, 1, n) {
                if (!vis[i]) {
                    cout << i << ' ';
                }
            }
            cout << n - 4 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n << endl;
        }
    } else {
        V<int> vis(n + 1, 0);
        int t = n, cnt = 0;
        while (t) {
            cnt++;
            t /= 2;
        }
        cout << (1LL << cnt) - 1 << endl;
        vis[n] = vis[(1LL << (cnt - 1)) - 1] = vis[(1LL << (cnt - 1)) - 2] =
            vis[1] = 1;

        FOR(i, 1, n) {
            if (!vis[i]) {
                cout << i << ' ';
            }
        }

        cout << 1 << ' ' << (1LL << (cnt - 1)) - 2 << ' '
             << (1LL << (cnt - 1)) - 1 << ' ' << n << endl;

        cout << endl;
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
