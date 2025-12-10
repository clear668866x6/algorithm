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
    int h, c, t;
    cin >> h >> c >> t;

    if ((h + c) / 2.0 >= t) {
        cout << 2 << endl;
        RE;
    }

    int l = 0, r = 1e8;

    auto calc = [&](int x) {
        int l = x / 2 + 1, r = x / 2;
        double p = (l * h + r * c) / (double)x;
        return p;
    };

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (calc(mid) >= (double)t)
            l = mid;
        else
            r = mid;
    }
    if (abs(calc(r) - (double)t) > abs(calc(r - 2) - (double)t)) r -= 2;
    cout << r << endl;
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
