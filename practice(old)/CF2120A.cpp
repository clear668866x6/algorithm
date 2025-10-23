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
    int l1, l2, l3, b1, b2, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if (l1 == l2 && l1 == l3) {
        if (b1 + b2 + b3 == l1) {
            YES;
            RE;
        }
    }

    if (b1 == b2 && b1 == b3) {
        if (l1 + l2 + l3 == b1) {
            YES;
            RE;
        }
    }

    if ((b2 + b3 == b1 && l2 == l3 && l2 + l1 == b1) || (l2 + l3 == l1 && b2 == b3 && b2 + b1 == l1)) {
        YES;
    } else {
        NO;
    }

}

signed main () {
    int Task = 1;

    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> Task;

    while (Task--) {
        solve ();
    }

    return 0;
}