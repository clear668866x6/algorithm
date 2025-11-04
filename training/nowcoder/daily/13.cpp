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
    int a, b;
    cin >> a >> b;

    int ans = 0;

    array<int, 13> day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto check = [&](int x) {
        int y = x / 10000, m = (x / 100) % 100, d = x % 100;
        bool isrun = false;
        if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0) isrun = true, day[2] = 29;

        if (m > 12 || m < 1) return false;
        if (d > day[m] || d < 1) return false;

        string s = to_string(x);
        string p = s;
        reverse(ALL(p));
        return p == s;
    };

    FOR(i, a, b) {
        if (check(i)) {
            ans++;
        }
    }
    cout << ans;
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