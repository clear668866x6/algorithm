#include <bits/stdc++.h>
#include <numeric>
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
    int n, k;
    cin >> n >> k;

    V<int> a(n + 1, 0);

    FOR(i, 1, n) cin >> a[i];

    int ans = 0;

    FOR(i, 1, n) ans += a[i] / k;

    V<int> mp(k, 0);

    FOR(i, 1, n) {
        mp[a[i] % k]++;
    }
    // cout << ans << endl;

    FOR(i, 1, k - 1) {
        int t = min(mp[i], mp[k - i]);
        if (k - i == i) {
            mp[i] -= t / 2, mp[k - i] -= t / 2;
            ans += t / 2;
        } else {
            mp[i] -= t, mp[k - i] -= t;
            ans += t;
        }
    }

    V<int> w;

    FOR(i, 0, k - 1) {
        if (mp[i]) w.eb(i);
    }

    FOR(l, 0, sz(w) - 1) {
        FORD(r, l, sz(w) - 1) {
            if (!mp[w[l]]) break;
            if (w[l] + w[r] >= k) {
                if (w[l] == w[r]) {
                    int t = mp[w[l]] / 2;
                    ans += t;
                    mp[w[l]] -= t;
                } else {
                    int t = min(mp[w[l]], mp[w[r]]);
                    ans += t;
                    mp[w[l]] -= t, mp[w[r]] -= t;
                }
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
