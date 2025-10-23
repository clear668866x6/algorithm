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
    int a, d, b, c, p;
    cin >> a >> d >> b >> c >> p;

    int mod = 998244353;

    auto qmi = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    queue<int> q1, q2;

    V<int> d1(p + 1, 1e18), d2(p + 1, 1e18);
    d1[a] = 0, d2[d] = 0;
    q1.push(a), q2.push(d);

    while (sz(q1)) {
        int t = q1.front();
        q1.pop();

        int c1 = (t + b) % p;
        if (d1[c1] > d1[t] + 1) {
            d1[c1] = d1[t] + 1;
            q1.push(c1);
        }
        c1 = (t * c) % p;
        if (d1[c1] > d1[t] + 1) {
            d1[c1] = d1[t] + 1;
            q1.push(c1);
        }
    }

    while (sz(q2)) {
        int t = q2.front();
        q2.pop();

        int c1 = (t + b) % p;
        if (d2[c1] > d2[t] + 1) {
            d2[c1] = d2[t] + 1;
            q2.push(c1);
        }
        c1 = (t * c) % p;
        if (d2[c1] > d2[t] + 1) {
            d2[c1] = d2[t] + 1;
            q2.push(c1);
        }
    }

    int ans = 1e18;

    FOR(i, 0, p - 1) {
        if (d1[i] != 1e18 && d2[i] != 1e18) {
            ans = min(ans, (qmi(2, d1[i]) - 1 + qmi(2, d2[i]) - 1) % mod);
        }
    }

    if (ans == 1e18) ans = -1;

    cout << ans << endl;
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