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
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    int len = r - l + 1;

    int mn = (1 + len) * len / 2;
    int mx = (n + n - len + 1) * len / 2;

    if (s < mn || s > mx) {
        cout << -1 << endl;
        RE;
    }

    V<int> ans(n + 1, 0);
    FOR(i, l, r) ans[i] = i - l + 1;

    s -= mn;

    while (s) {
        FORD(i, l, r) {
            ans[i]++;
            s--;
            if (!s) break;
        }
    }

    V<int> vis(n + 1, 0);
    FOR(i, 1, n) {
        vis[ans[i]] = 1;
    }

    FOR(i, 1, n) {
        if (i >= l && i <= r) continue;
        FOR(j, 1, n) {
            if (!vis[j]) {
                vis[j] = 1;
                ans[i] = j;
                break;
            }
        }
    }

    FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
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
