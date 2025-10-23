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

    V<int> d(n + 1, 0);
    V<V<int>> g(n + 1);

    FOR(i, 2, n) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
        d[a]++, d[b]++;
    }

    if (n == 1) {
        cout << -1 << endl;
        RE;
    }

    bool f = false;

    FOR(i, 1, n) {
        if (d[i] > 2) {
            f = 1;
            break;
        }
    }

    if (!f) {
        cout << -1 << endl;
        RE;
    }

    int b = -1;
    int c = -1;

    FOR(i, 1, n) {
        if (d[i] > 2) {
            for (auto x : g[i]) {
                if (d[x] == 1) {
                    b = i;
                    c = x;
                    break;
                }
            }
            if (c != -1) break;
        }
    }

    if (b == -1) {
        FOR(i, 1, n) {
            if (d[i] > 2) {
                b = i;
                break;
            }
        }
        int a1 = g[b][0], a2 = g[b][1];
        cout << a1 << ' ' << b << ' ' << a2 << endl;
    } else {
        int a = -1;
        for (auto x : g[b]) {
            if (x != c) {
                a = x;
                break;
            }
        }
        cout << a << ' ' << b << ' ' << c << endl;
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
