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
    int n, x;
    cin >> n >> x;

    int t1 = n + x - 2, t2 = n - x;

    set<int> s;

    FOR(i, 1, t1 / i) {
        if (t1 % i == 0) {
            s.insert(i);
            s.insert(t1 / i);
        }
    }

    FOR(i, 1, t2 / i) {
        if (t2 % i == 0) {
            s.insert(i);
            s.insert(t2 / i);
        }
    }

    int ans = 0;

    for (auto t : s) {
        if (!(t & 1)) {
            if ((t + 2) / 2 >= x) {
                ans++;
            }
        }
    }

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
