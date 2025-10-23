#include <bits/stdc++.h>
#include <functional>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template <class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define FOR2(i, a, b, c) for (auto i = (a); i <= (b); i += c)
#define FORD(i, b, a) for (auto i = (a); i >= (b); i--)
#define FORD2(i, b, a, c) for (auto i = (a); i >= (b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x) & (-x))
#define RE return;
#define fi first
#define se second

void solve() {}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;

    function<i128(i128, i128)> qmi = [&](i128 a, i128 b) {
        i128 res = 1;
        while (b) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };

    map<int, int> mp;

    FOR(x, 3, 60) {
        FOR(k, 2, 1e6) {
            i128 t = qmi(k, x) - 1;
            if (t / (k - 1) > 1e18)
                break;
            if (t % (k - 1))
                continue;
            mp[t / (k - 1)]++;
        }
    }

    function<void(void)> solve = [&]() {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "NO" << endl;
            RE;
        }

        if (mp[n]) {
            cout << "YES" << endl;
            RE;
        }

        int l = 2, r = 1e9 + 10;

        function<int(int)> check = [&](int k) {
            i128 t = qmi(k, 3) - 1;
            if (t / (k - 1) >= n)
                return 1;
            if (t % (k - 1))
                return 1;
            return 0;
        };

        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }

        i128 t1 = qmi(r, 3) - 1, t2 = qmi(l, 3) - 1;
        if (t1 / (r - 1) == n || t2 / (l - 1) == n) {
            cout << "YES" << endl;
            RE;
        }
        cout << "NO" << endl;
    };

    while (Task--) {
        solve();
    }

    return 0;
}
