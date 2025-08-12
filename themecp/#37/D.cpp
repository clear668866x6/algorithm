#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int n, k, q;
    cin >> n >> k;

    V<int> p(n + 1, 0), d(n + 1, 0);

    FOR(i, 1, n) cin >> p[i];
    FOR(i, 1, n) cin >> d[i];

    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        bool f = false;

        int t = x;
        map<int, int> mp;

        while (1) {
            // cout << t << endl;
            if (mp[t] >= 2) {
                NO;
                break;
            }
            if (!f) {
                int l = upper_bound(ALL(p), t) - p.begin() - 1;
                bool ff = false;
                _(l);
                FOR(i, l + 1, n) {
                    if ((p[i] - t) % k == d[i]) {
                        t = p[i];
                        ff = true;
                        break;
                    }
                }
                mp[t]++;
                if (!ff) {
                    YES;
                    break;
                }
                f = 1;
            } else {
                int r = upper_bound(ALL(p), t) - p.begin() - 1;

                bool ff = false;
                _(r, r);
                FOR(i, 1, r) {
                    if ((p[i] - t) % k == d[i]) {
                        t = p[i];
                        ff = 1;
                        break;
                    }
                }

                if (!ff) {
                    YES;
                    break;
                }

                mp[t]++;

                f = 0;
            }
        }
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
