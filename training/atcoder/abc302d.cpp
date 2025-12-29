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
    int n, m, d;
    cin >> n >> m >> d;
    V<int> a(n + 1, 0), b(m + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    sort(ALL(b));

    int ans = -1;

    FOR(i, 1, n) {
        int l = 0, r = m + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (b[mid] - a[i] <= d)
                l = mid;
            else
                r = mid;
        }
        if (abs(b[l] - a[i]) <= d) {
            ans = max(ans, a[i] + b[l]);
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