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

V<int> f(1e6 + 1, 0);
auto init = []() -> int {
    FOR(i, 2, 1e6) {
        int t = i;
        f[i] = f[i - 1];
        while (t % 2 == 0) t /= 2, f[i]++;
    }
    return 0;
}();

void solve() {
    int T;
    cin >> T;

    auto qmi = [&](int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    };

    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << ' ';
        } else {
            cout << qmi(f[n] + 1, mod - 2) << ' ';
        }
    }
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