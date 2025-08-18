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

    V<V<int>> w(n + 1, V<int>(m + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> w[i][j];
        }
    }

    int l = 0, r = 1e12;

    function<int(int)> check = [&](int x) {
        V<array<int, 2>> s;
        FOR(j, 1, m) {
            bool f = false;
            FOR(i, 1, n) {
                if (w[i][j] >= x) {
                    f = 1;
                    s.pb({i, j});
                }
            }
            if (!f) {
                return 0;
            }
        }

        map<int, int> mp;

        for (auto [x, y] : s) {
            if (mp[x]) {
                return 1;
            }
            mp[x]++;
        }


        return 0;
    };


    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
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
