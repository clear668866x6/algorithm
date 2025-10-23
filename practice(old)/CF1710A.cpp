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
#define sz size()

void solve() {
    int n, m, k;

    cin >> n >> m >> k;

    V<int> a(k);

    for (auto &x : a)
        cin >> x;
    sort(ALL(a));

    if (a.back() >= n * m) {
        Yes;
        RE;
    }

    function<int(int, int)> check = [&](int n, int m) {
        bool f = false;
        FORD(i, 0, k - 1) {
            int t = (a[i] / n);
            if (t < 2)
                continue;
            if (t >= 3)
                f = 1;
            if (m - t < 0) {
                if (!f && m == 1) {
                    return 0;
                }
            }
            m -= t;
        }
        if (m <= 0) {
            return 1;
        }
        return 0;
    };

    if (check(n, m) || check(m, n)) {
        Yes;
    } else {
        No;
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
