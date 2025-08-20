#include <bits/stdc++.h>
#include <functional>
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

struct ST {
    V<V<int>> f;
    int n;
    ST() {}
    ST(int x, V<int> w) {
        f.resize(x + 10, V<int>(22, 0));
        n = x;
        FOR(j, 0, 20) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                if (!j)
                    f[i][j] = w[i];
                else
                    f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = __lg(r - l + 1);

        return gcd(f[l][len], f[r - (1 << len) + 1][len]);
    }
};

void solve() {
    int n;
    cin >> n;

    V<int> w(2 * n + 1, 0);

    FOR(i, 1, n) cin >> w[i];

    int t = 0;

    FOR(i, 1, n) t = gcd(t, w[i]);

    FOR(i, 1, n) w[i + n] = w[i];

    ST A(n * 2, w);

    int l = -1, r = n + 1;

    function<int(int)> check = [&](int x) {
        FOR(i, 1, n) {
            if (A.query(i, i + x) != t) {
                return 0;
            }
        }
        return 1;
    };

    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
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
