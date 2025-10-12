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
    int len = n * 2;

    V<int> ans(len + 1, 0);
    V<int> vis(len + 1, 0);
    V<int> c;

    auto query = [&]() {
        int t = sz(c);
        cout << "? " << t << ' ';
        for (auto x : c) {
            cout << x << ' ';
        }
        cout << endl;
        int x;
        cin >> x;
        return x;
    };

    FOR(i, 1, len) {
        c.eb(i);
        int x = query();
        if (!x) {
            vis[i] = 1;
        } else {
            c.pop_back();
            ans[i] = x;
        }
    }

    c.clear();

    FORD(i, 1, len) {
        c.eb(i);
        if (vis[i]) {
            int x = query();
            ans[i] = x;
            c.pop_back();
        }
    }

    cout << "! ";
    FOR(i, 1, len) cout << ans[i] << ' ';
    cout << endl;
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
