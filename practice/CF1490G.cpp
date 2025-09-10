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
    int n, q;
    cin >> n >> q;

    V<int> w(n);

    for (auto &x : w) cin >> x;

    V<int> pre(n + 1, 0);

    FOR(i, 1, n) pre[i] = pre[i - 1] + w[i - 1];
    ;

    V<array<int, 2>> ss(n + 1);

    FOR(i, 1, n) ss[i] = {pre[i], i};

    sort(ss.begin() + 1, ss.end());

    V<int> suf(n + 2, 1e18);

    FORD(i, 1, n) {
        suf[i] = min(suf[i + 1], ss[i][1]);
    }

    int mx = *max_element(pre.begin() + 1, pre.end());

    while (q--) {
        int x;
        auto calc = [&](int r) {
            int del = x - r * pre[n];
            int tt = suf[(lower_bound(ss.begin() + 1, ss.end(), array<int, 2>{del, -1}) - ss.begin())];
            return (r * n + tt - 1);
        };
        cin >> x;

        int l = -1, r = 1e9 + 2;

        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (pre[n] * mid + mx >= x)
                r = mid;
            else
                l = mid;
        }
        if (r == 1e9 + 2) {
            if (x <= mx) {
                cout << calc(0) << " \n"[!q];
            } else {
                cout << -1 << " \n"[!q];
            }
            continue;
        }

        if (mx >= x) {
            cout << suf[(lower_bound(ss.begin() + 1, ss.end(), array<int, 2>{x, -1}) - ss.begin())] - 1 << " \n"[!q];
            continue;
        } else if (pre[n] <= 0) {
            cout << -1 << " \n"[!q];
            continue;
        }

        cout << calc(r) << " \n"[!q];
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
