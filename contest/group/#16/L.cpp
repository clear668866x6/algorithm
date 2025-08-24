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
    int n, l, r;
    cin >> n >> l >> r;

    V<int> w(n + 2, 0);

    FOR(i, 1, n) cin >> w[i];

    V<int> pre(n + 2, 0);

    FOR(i, 1, n) {
        pre[i] = pre[i - 1] ^ w[i];
    }

    if (l <= n) {
        cout << w[l] << endl;
    } else {
        if (l / 2 <= n) {
            cout << pre[l / 2] << endl;
            RE;
        }
        l /= 2;
        if (!(n & 1)) {
            n++;
            pre[n] = pre[n - 1] ^ (pre[n / 2]);
        }

        if (l & 1) {
            cout << pre[n] << endl;
        } else {
            int t = l;
            int ans = pre[n];
            while (t > n) {
                t /= 2;
                if (t <= n) {
                    ans ^= pre[t];
                } else {
                    if (t & 1) {
                        ans ^= pre[n];
                        break;
                    } else {
                        ans ^= pre[n];
                    }
                }
            }
            cout << ans << endl;
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
