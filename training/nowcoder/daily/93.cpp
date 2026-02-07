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
    int n, m, x;
    cin >> n >> m >> x;
    V<int> a(n + 1, 0);
    FOR(i, 1, n) cin >> a[i];

    int s = 0, ans = 0;

    FOR(i, 1, m) s += a[i];

    if (s > x) {
        ans += (s - x);
        FORD(i, 1, m) {
            if (s - a[i] < x) {
                a[i] -= (s - x);
                s = x;
            } else {
                s -= a[i];
                a[i] = 0;
            }
        }
    }

    FOR(i, m + 1, n) {
        s -= a[i - m];
        s += a[i];
        if (s > x) {
            ans += (s - x);
            a[i] -= (s - x);
            s = x;
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