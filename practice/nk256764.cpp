#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T>
using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += c)
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i >= (int)(b); i -= c)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define lowbit(x) ((x)&(-x))
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

void solve () {
    int n;
    cin >> n;

    int x = 1, y = 1, ans = 1e18;

    int t = 1;

    FOR (i, 1, 18) {
        if (i == 1) {
            ans = n;
            continue;
        }
        if (i == 2) {
            t = 2;
            continue;
        }
        t *= i;
        int p1 = n / (t - 1);
        int p2 = p1 + 1;
        if (abs ((t - 1) * p1 - n) < ans) {
            ans = abs ((t - 1) * p1 - n);
            if (p1 != 2) {
                x = i, y = p1;
            }
        }
        if (abs ((t - 1) * p2 - n) < ans) {
            ans = abs ((t - 1) * p2 - n);
            if (p2 != 2) {
                x = i, y = p2;
            }
        }
    }
    cout << x << ' ' << y;
}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    while (Task--) {
        solve ();
    }

    return 0;
}