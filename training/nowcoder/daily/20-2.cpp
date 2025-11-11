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
    int n, k;
    cin >> n >> k;

    int mx = 0;
    V<int> len(n + 1, 0);

    FOR(i, 1, n) {
        int t = n - i, p = 0;
        while (t) {
            p++;
            t /= 2;
        }
        len[i] = p;
        mx += p;
    }

    if (k > mx) {
        cout << -1 << endl;
        RE;
    }

    V<int> ans;
    V<int> vis(n + 1, 0);

    FOR(i, 1, n) {
        if (k >= len[i]) {
            k -= len[i];
            vis[i] = 1;
            ans.eb(i);
        }
    }
    reverse(ALL(ans));
    FOR(i, 1, n) {
        if (!vis[i]) cout << i << ' ';
    }
    for (auto x : ans) cout << x << ' ';
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}