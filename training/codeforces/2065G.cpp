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
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    map<int, int> p1, p2;
    map<array<int, 2>, int> p3;
    map<int, int> p4, p5;
    int t1 = 0, t2 = 0;
    int ans = 0;

    FOR(i, 1, n) {
        int t = w[i];
        V<array<int, 2>> p;
        FOR(j, 2, t / j) {
            if (t % j == 0) {
                int c = 0;
                while (t % j == 0) t /= j, c++;
                p.pb({j, c});
            }
        }
        if (t > 1) {
            p.pb({t, 1});
        }

        if (sz(p) == 1) {
            auto [px, c] = p[0];
            if (c == 1) {
                p1[px]++;
                t1++;
            } else if (c == 2) {
                p2[px]++;
                t2++;
            }
        }
        // p1*p2
        if (sz(p) == 2) {
            auto [x1, c1] = p[0];
            auto [x2, c2] = p[1];
            if (c1 == 1 && c2 == 1) {
                p3[{x1, x2}]++;
                p4[x1]++;
                p5[x2]++;
            }
        }
    }

    // p1
    for (auto [x, y] : p1) {
        ans += y * (t1 - y + p2[x] + p4[x] + p5[x]);
    }
    // p1^2
    for (auto [x, y] : p2) {
        ans += (y * (p1[x] + y + 1));
    }

    // p1*p2

    for (auto [x, y] : p3) {
        auto [x1, x2] = x;
        ans += y * (p1[x1] + p1[x2] + y + 1);
    }

    cout << ans / 2 << endl;
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
