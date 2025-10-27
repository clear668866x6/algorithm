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

struct EXGCD {

    int exgcd(int a, int b, int &x, int &y) {
        if (!b) {
            x = 1, y = 0;
            return a;
        }
        int d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
} A;

void solve() {
    int a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;

    if ((b2 - b1) % gcd(a1, a2)) {
        cout << 0 << endl;
        RE;
    }

    int x, y;
    int d = A.exgcd(a1, -a2, x, y);
    x *= (b2 - b1);
    x /= d;

    int dx = abs(a2 / d), dy = abs(a1 / d);

    x = (x % dx + dx) % dx;
    y = (a1 * x - (b2 - b1)) / a2;

    if (y < 0) {
        y = (y % dy + dy) % dy;
        x = (a2 * y + (b2 - b1)) / a1;
    }

    int L = max<int>(0, (int)ceil((l - a1 * x - b1) * 1.0 / (a1 * dx))),
        R = (int)floor((r - a1 * x - b1) * 1.0 / (a1 * dx));

    // cout << d << ' ' << x << ' ' << y;

    cout << max<int>(0, R - L + 1);
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