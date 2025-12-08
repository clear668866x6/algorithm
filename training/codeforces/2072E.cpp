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
    int k;
    cin >> k;

    int cnt = 1, lst = 1;

    V<PII> ans;

    while (k > 0) {
        int l = 1, r = 1e9;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid * (mid - 1) / 2 <= k)
                l = mid;
            else
                r = mid;
        }
        int t = k - l * (l - 1) / 2;

        FOR(i, lst, lst + l - 1) ans.pb({cnt, i});
        cnt++;
        lst += l;
        k = t;
    }

    cout << sz(ans) << endl;
    for (auto [x, y] : ans) cout << x << ' ' << y << endl;
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
