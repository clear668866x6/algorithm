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
    int n, m, q;
    cin >> n >> m >> q;

    V<int> a(n), b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(RALL(a)), sort(RALL(b));

    V<int> prea(n + 1, 0), preb(m + 1, 0);

    FOR(i, 1, n) prea[i] = prea[i - 1] + a[i - 1];
    FOR(i, 1, m) preb[i] = preb[i - 1] + b[i - 1];

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        int l = max<int>(0, z - y), r = min(x, z);
        if (l > r) {
            cout << 0 << endl;
            continue;
        }

        while (r - l > 2) {
            int mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
            int t1 = prea[mid1] + preb[z - mid1];
            int t2 = prea[mid2] + preb[z - mid2];
            if (t1 < t2) {
                l = mid1;
            } else
                r = mid2;
        }

        int ans = 0;

        FOR(i, l, r) {
            ans = max(ans, prea[i] + preb[z - i]);
        }
        cout << ans << endl;
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
