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
    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> c, r;

    V<int> x(k + 1, 0), y(k + 1, 0);

    FOR(i, 1, k) {
        cin >> x[i] >> y[i];
        c[x[i]]++, r[y[i]]++;
    }

    int c1 = (n - sz(c)) * (m - sz(r)) % mod;
    int c2 = 0;

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    FOR(i, 1, k) {
        if (c[x[i]] == 1 && c[y[i]] == 1) {
            c2++;
        }
    }

    int ans = 0;
    int t1 = (n - 1) * (m - 1) % mod - k;
    if (t1 < 0) t1 += mod;
    int t2 = (t1 + 1) % mod;

    ans += (c1 * qmi(2, t1) % mod + c2 * qmi(2, t2) % mod) % mod;

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
