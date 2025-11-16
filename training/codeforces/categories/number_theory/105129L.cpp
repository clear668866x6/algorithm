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

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    array<int, 15> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    set<int> c;
    FOR(i, 0, (1 << 15) - 1) {
        int t = 1;
        FOR(j, 0, 14) {
            if (__builtin_popcount(i) < 1) break;
            if (i >> j & 1) {
                t *= (p[j]);
            }
        }
        if (__builtin_popcount(i) >= 1) {
            c.insert(t);
        }
    }

    auto solve = [&]() {
        int n;
        cin >> n;
        V<int> vis(60, 0);
        FOR(i, 1, n) {
            int x;
            cin >> x;
            vis[x] = 1;
        }

        for (auto x : c) {
            bool f = false;
            FOR(i, 0, 50) {
                if (vis[i] && gcd(i, x) == 1) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << x << endl;
                RE;
            }
        }
    };

    while (Task--) {
        solve();
    }

    return 0;
}
