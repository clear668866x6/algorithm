#include <bits/stdc++.h>
using namespace std;

#define int int64_t
// #define endl "\n"

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

    auto query = [&](int i, int x) {
        cout << "? " << i << ' ' << x << endl;
        int b;
        cin >> b;
        return b;
    };

    V<int> c, vis(n + 1, 0);

    FOR(i, 1, n) {
        c.eb(i);
    }

    int t = 1;
    FOR(k, 0, 30) {
        if (sz(c) == 1) {
            cout << "! " << c.back() << endl;
            RE;
        }

        V<int> c0, c1;
        for (auto x : c) {
            if (x & t) {
                c1.eb(x);
            } else {
                c0.eb(x);
            }
        }

        // for (auto x : c0) cout << x << ' ';
        // cout << endl;
        // for (auto x : c1) cout << x << ' ';
        // cout << endl;
        int cnt = 0;
        V<int> vis1 = vis, vis2 = vis;
        FOR(i, 1, n - 1) {
            if (!vis[i]) {
                if (query(i, t)) {
                    cnt++;
                    vis1[i] = 1;
                } else {
                    vis2[i] = 1;
                }
            }
        }

        if (cnt == sz(c1)) {
            // push 0
            c = c0;
            vis = vis1;
        } else {
            c = c1;
            vis = vis2;
        }

        // cout << "--------------------" << endl;
        // for (auto x : c) {
        //     cout << x << ' ';
        // }
        // cout << endl;
        // cout << "cnt= " << cnt << endl;
        // cout << "--------------------" << endl;
        // cout << endl;

        t = t * 2;
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
