#include <algorithm>
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
    V<int> b(10, 0);
    FOR(i, 1, n) cin >> w[i], b[w[i]] = 1;

    V<int> c;
    FOR(i, 1, 8) {
        if (b[i]) {
            c.eb(i);
        }
    }

    int ans = 1e18;

    FOR(i, 1, 8) {
        if (b[i]) {
            V<int> pp = b;
            int fs = i, tot = 0, bei = i;
            FOR(idx, 1, sz(c) - 1) {
                int p = 9, idx2 = 0;
                FOR(j, 1, 8) {
                    if (pp[j] && bei != j) {
                        int t = min(abs(fs - j), 8 - abs(fs - j));
                        if (p > t) {
                            p = t;
                            idx2 = j;
                        }
                    }
                }
                pp[idx2]--;
                fs = idx2;
                tot += p;
            }
            ans = min(ans, tot);
        }
    }

    cout << ans << endl;
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
