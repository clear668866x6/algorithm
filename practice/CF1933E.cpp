#include <algorithm>
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
#define sz size()

void solve() {
    int n;
    cin >> n;

    V<int> w(n + 1, 0), pre(n + 2, 0);
    FOR(i, 1, n) cin >> w[i], pre[i] = pre[i - 1] + w[i];

    int q;
    cin >> q;
    while (q--) {
        int x, u;
        cin >> x >> u;

        int l = x - 1, r = n + 1;

        function<int(int, int)> check = [&](int x, int L) {
            int t = pre[x] - pre[L - 1];
            return (t >= u);
        };

        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (check(mid, x))
                r = mid;
            else
                l = mid;
        }

        if (r - 1 < x) {
            cout << r << ' ';
            continue;
        }

        int c1 = (pre[r - 1] - pre[x - 1]), c2 = (pre[r] - pre[x - 1]);
        int t1 = u * c1 - c1 * (c1 - 1) / 2, t2 = u * c2 - c2 * (c2 - 1) / 2;
        if (t1 >= t2)
            r--;
        cout << r << ' ';
    }
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
