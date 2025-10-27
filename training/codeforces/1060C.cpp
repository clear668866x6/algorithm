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
    V<int> a(n + 1, 0), b(m + 1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    int x;
    cin >> x;
    V<int> p1(n + 1, 0), p2(m + 1, 0);
    FOR(i, 1, n) p1[i] = p1[i - 1] + a[i];
    FOR(i, 1, m) p2[i] = p2[i - 1] + b[i];

    int ans = 0;
    V<int> mn1(2010, 1e18), mn2(2010, 1e18);

    FOR(i, 1, n) {
        FOR(j, i, n) {
            mn1[j - i + 1] = min(mn1[j - i + 1], p1[j] - p1[i - 1]);
        }
    }

    FOR(i, 1, m) {
        FOR(j, i, m) {
            mn2[j - i + 1] = min(mn2[j - i + 1], p2[j] - p2[i - 1]);
        }
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (mn1[i] * mn2[j] <= x) {
                ans = max(ans, i * j);
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