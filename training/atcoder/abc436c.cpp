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

    set<array<int, 2>> s;

    int ans = 0;

    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        FOR(c1, 0, 1) {
            FOR(c2, 0, 1) {
                int a = x + c1, b = y + c2;
                if (a < 1 || b < 1 || a > n || b > n) continue;
                if (s.count({a, b})) continue;
                cnt++;
            }
        }
        if (cnt == 4) {
            ans++;
            FOR(c1, 0, 1) {
                FOR(c2, 0, 1) {
                    int a = x + c1, b = y + c2;
                    s.insert({a, b});
                }
            }
        }
    }
    cout << ans;
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