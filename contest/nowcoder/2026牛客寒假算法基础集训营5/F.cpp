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
    int n, a, b;
    cin >> n >> a >> b;

    int t1 = (n / 8) * (a + b) + (n - n / 8 * 8) / 2 * b, t2 = (n / 2 * b);
    int t3 = (n / 8) * (a + b) + (n - n / 8 * 8) / 7 * a;
    int t4 =
        (n / 7) * a + ((n - n / 7 * 7) > n / 7 ? n / 7 * b + (n - n / 7 * 7 - n / 7) / 2 * b : (n - n / 7 * 7) * b);

    int ans = max({t1, t2, t3, t4});

    auto calc = [&](int i) {
        if (i < 0) i = 0;
        if (i * 7 > n) return (int)0;
        int t5 = i * a + ((n - 7 * i) > i ? i * b + (n - 8 * i) / 2 * b : (n - 7 * i) * b);
        return t5;
    };

    ans = max(ans, calc(n / 8));
    ans = max(ans, calc(n / 8 + 1));
    ans = max(ans, calc(n / 7 - 1));
    ans = max(ans, calc(n / 7));

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
