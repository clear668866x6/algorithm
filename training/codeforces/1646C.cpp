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

struct Pre {
    V<int> p{1, 1};
    int cnt;

    void init() {
        int t = 1;
        int idx = 2;
        while (t <= 1e12) {
            t *= idx;
            idx++;
            p.eb(t);
        }
        cnt = sz(p);
    }
} A;

void solve() {
    int n;
    cin >> n;

    int ans = __builtin_popcountll(n);

    FOR(state, 0, (1 << A.cnt) - 1) {
        int del = 0;
        FOR(j, 0, A.cnt - 1) {
            if (state >> j & 1) {
                del += A.p[j];
            }
        }
        if (del > n) continue;
        ans = min<int>(ans, __builtin_popcountll(n - del) + __builtin_popcountll(state));
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}
