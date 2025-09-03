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
    int n, m;
    cin >> n >> m;

    set<int> s;

    FOR(i, 1, m) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int mod = 1e9 + 7;

    V<int> f(n + 1, 0);

    if (s.count(1) && !s.count(2)) {
        f[2] = 1;
    } else if (!s.count(1) && s.count(2)) {
        f[1] = 1;
    } else if (!s.count(1) && !s.count(2)) {
        f[1] = 1, f[2] = 2;
    }

    FOR(i, 3, n) {
        if (s.count(i - 1) && !s.count(i - 2)) {
            f[i] = f[i - 2];
        } else if (!s.count(i - 1) && s.count(i - 2)) {
            f[i] = f[i - 1];
        } else if (!s.count(i - 1) && !s.count(i - 2)) {
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        }
    }

    cout << f[n];
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