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

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    V<set<int>> mp(35);

    FOR(v, 0, 32) {
        FOR(i, 1, n) {
            int t = (w[i] >> v) & 1;
            if (t) {
                mp[v].insert(i);
            }
        }
    }

    auto qmi = [&](int a, int b) {
        if (b <= 0) return (int)0;
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    int ans = 0;

    FOR(i, 2, n) {
        int t = 0;
        FOR(v, 0, 32) {
            auto it = mp[v].lower_bound(i);
            if (it != mp[v].begin()) {
                it--;
                if (w[i] >> v & 1) {
                    t = max(t, *it + 1);
                } else {
                    t = max(t, *it);
                }
            }
        }
        ans += qmi(2, i - t);
        ans %= mod;
    }
    if (!ans) ans = 1;
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
