#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #include <bits/debug.h>
#endif

#define int int64_t
#define endl "\n"

using PII = pair<int, int>;
using TII = tuple<int, int, int>;
template<class T> using V = vector<T>;
using i64 = long long;
using i128 = __int128;
using u64 = unsigned long long;

#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR2(i, a, b, c) for (int i = (int)(a); i <= (int)(b); i += (int)(c))
#define FORD(i, b, a) for (int i = (int)(a); i >= (int)(b); i--)
#define FORD2(i, b, a, c) for (int i = (int)(a); i <= (int)(b); i -= (int)(c))
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
    int x;
    cin >> x;

    int a = 0, b = 0;
    bool f = false;

    FORD(i, 0, 30) {
        if (!f && x >> i & 1) {
            a |= (1LL << i);
            f = 1;
        }
        if (f && !(x >> i & 1)) {
            int t1 = a | (1LL << i);
            int t2 = b | (1LL << i);

            if (t1 + t2 <= 2 * x) {
                a = t1, b = t2;
            }
        } else if (f && (x >> i & 1)) {
            int t1 = a | (1 << i);
            if (t1 + b <= 2 * x) {
                a = t1;
            } else {
                int t2 = b | (1 << i);
                if (a + t2 <= 2 * x) {
                    b = t2;
                } else {
                    cout << -1 << endl;
                    RE;
                }
            }
        }
    }

    if ((a ^ b) != x || (a + b) != 2 * x) {
        cout << -1 << endl;
    } else {
        cout << a << ' ' << b << endl;
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
