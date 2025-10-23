#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;

    V<array<int, 2>> a(n), b(n);
    FOR(i, 0, n - 1) {
        cin >> a[i][0] >> a[i][1] >> b[i][0] >> b[i][1];
        if (1. * a[i][1] / a[i][0] > 1. * b[i][1] / b[i][0])
            swap(a[i], b[i]);
    }

    int l = 0, r = 1e9 + 10;

    function<int(int)> check = [&](int x) {
        int ans = 0;
        FOR(i, 0, n - 1) {
            int cnt = 1e18;
            FOR(j, 0, 100) cnt = min(cnt, b[i][1] * j + (x - b[i][0] * j + a[i][0] - 1) / a[i][0] * a[i][1]);
            ans += cnt;
        }
        return ans <= m;
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

    while (Task--) {
        solve();
    }

    return 0;
}