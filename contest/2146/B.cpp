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
    int n, m;
    cin >> n >> m;
    V<V<int>> g(n + 1);
    map<int, int> mp;
    FOR(i, 1, n) {
        int len;
        cin >> len;
        while (len--) {
            int x;
            cin >> x;
            mp[x]++;
            g[i].eb(x);
        }
    }

    if (sz(mp) != m) {
        NO;
    } else {
        int cnt = 0;
        FOR(i, 1, n) {
            map<int, int> mp2;
            for (auto j : g[i]) {
                mp2[j]++;
            }
            bool f = false;
            for (auto j : g[i]) {
                if (mp[j] - mp2[j] == 0) {
                    f = 1;
                    break;
                }
            }
            if (!f) cnt++;
        }
        if (cnt > 1) {
            YES;
        } else {
            NO;
        }
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
