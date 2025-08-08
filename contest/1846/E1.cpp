#include <bits/stdc++.h>
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

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "NO" << endl;
        RE;
    }

    function<int(int, int)> qmi = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };

    FOR(x, 3, 30) {
        FOR(k, 2, n) {
            int t = qmi(k, x) - 1;
            if (t / (k - 1) > n)
                break;
            if (t % (k - 1))
                continue;
            if (t / (k - 1) == n) {
                cout << "YES" << endl;
                RE;
            }
        }
    }
    cout << "NO" << endl;
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