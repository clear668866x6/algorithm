#include <algorithm>
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
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    map<int, int> mp;
    FOR(i, 1, n) cin >> w[i], mp[w[i]]++;
    sort(ALL(w));
    V<int> odd, even;

    for (auto [x, y] : mp) {
        if (y & 1) {
            int p = y / 2 * 2;
            while (p--) {
                even.eb(x);
            }
            odd.eb(x);
        } else {
            while (y--) {
                even.eb(x);
            }
        }
    }

    int n1 = sz(even), n2 = sz(odd);
    int ans = 0;

    V<int> pre(n1 + 1, 0);

    FOR(i, 1, n1) pre[i] = pre[i - 1] + even[i - 1];

    FORD2(i, 1, n1, 2) {
        int p = pre[i];
        int a = 0;
        if (sz(odd)) {
            auto it = upper_bound(ALL(odd), even[i - 1]);
            if (it != odd.begin()) {
                a = *prev(it);
            }
            auto it2 = upper_bound(ALL(odd), even[i - 1]);
            int mx = even[i - 1];
            if (it2 != odd.end()) {
                mx = max(mx, *it2);
                if (pre[i] + a > mx) {
                    ans = max(ans, pre[i] + a + mx);
                }
            } else {
                if (pre[i] + a - mx > mx) {
                    ans = max(ans, pre[i] + a);
                }
            }

            a = 0;
            int b = 0;
            auto it3 = upper_bound(ALL(odd), even[i - 1]);
            if (it3 != odd.begin()) {
                a = *prev(it3);
                if (prev(it3) != odd.begin()) {
                    b = *(prev(prev(it3)));
                }
            }

            if (pre[i - 1] + a + b > even[i - 1]) {
                ans = max(ans, pre[i] + a + b);
            }

        } else {
            if (pre[i - 1] > even[i - 1]) {
                ans = max(ans, pre[i]);
            }
        }
    }

    cout << ans << endl;
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
