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

    V<int> a(n + 1, 0), b(n + 1, 0);

    FOR(i, 1, n) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            swap(a[i], b[i]);
    }

    int lst = b[1];

    FOR(i, 2, n) {
        if (lst >= b[i]) {
            lst = b[i];
        } else if (lst >= a[i]) {
            lst = a[i];
        } else {
            cout << "NO" << endl;
            RE;
        }
    }
    cout << "YES" << endl;
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