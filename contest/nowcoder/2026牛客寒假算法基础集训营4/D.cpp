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

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    i128 d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    int a, b, c;
    cin >> c >> a >> b;

    int g = gcd(a, b);
    int a0 = a / g, b0 = b / g, c0 = c / g;
    if (c % g) {
        No;
        RE;
    }

    i128 x, y;
    exgcd(a, b, x, y);
    x *= c0, y *= c0;
    auto mod = [&](int a, int b) {
        int t = (a % b + b) % b;
        return t;
    };
    x = mod(x, b0);

    if (x < 0 || (c - x * a) / b < 0) {
        No;
        RE;
    }
    Yes;

    i128 l = -1, r = 1e18;

    auto check = [&](i128 val) {
        if (val < 0) return pair((i128)2e18, (i128)2e18);
        i128 x2 = x + val * b0;
        i128 y2 = (c - x2 * a) / b;
        return pair(x2, y2);
    };

    while (l + 1 < r) {
        i128 mid = (l + r) / 2;
        auto [x1, y1] = check(mid);
        if (x1 >= y1)
            r = mid;
        else
            l = mid;
    }

    auto [ansx1, ansy1] = check(r);
    auto [ansx2, ansy2] = check(r - 1);
    auto [ansx3, ansy3] = check(r - 2);

    i128 ans1 = max(ansx1, ansy1), ans2 = max(ansx2, ansy2), ans3 = max(ansx3, ansy3);

    i128 t = min({ans1, ans2, ans3});

    if (t == ans1) {
        cout << format("{} {}", ansx1, ansy1) << endl;
    } else if (t == ans2) {
        cout << format("{} {}", ansx2, ansy2) << endl;
    } else {
        cout << format("{} {}", ansx3, ansy3) << endl;
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
