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

constexpr int mod = 998244353;

struct E {
    static constexpr int N = 1e7 + 10;

    int minp[N];

    void init() {
        int n = N - 10;
        FOR(i, 2, n) {
            FOR2(j, i, n, i) {
                if (!minp[j]) minp[j] = i;
            }
        }
    }

    int qmi(int a, int b) {
        int ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

} A;

void solve() {
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    map<int, int> mx1, mx2, cmx1, cmx2;

    FOR(i, 1, n) {
        int t = w[i];
        while (t > 1) {
            int p = A.minp[t], cnt = 0;
            while (t % p == 0) t /= p, cnt++;
            if (cnt > mx1[p]) {
                mx2[p] = mx1[p];
                cmx2[p] = cmx1[p];
                mx1[p] = cnt;
                cmx1[p] = 1;
            } else if (cnt == mx1[p]) {
                cmx1[p]++;
            } else if (cnt > mx2[p]) {
                mx2[p] = cnt;
                cmx2[p] = 1;
            } else if (cnt == mx2[p]) {
                cmx2[p]++;
            }
        }
    }

    int ans = 1;

    for (auto &[x, y] : mx1) {
        ans = ans * A.qmi(x, y);
        ans %= mod;
    }

    FOR(i, 1, n) {
        int t = w[i];
        int res = ans;
        while (t > 1) {
            int p = A.minp[t], cnt = 0;
            while (t % p == 0) t /= p, cnt++;
            if (cnt == mx1[p]) {
                if (cmx1[p] == 1) {
                    int del = mx1[p] - mx2[p];
                    int tp = A.qmi(p, del);
                    res = res * A.qmi(tp, mod - 2) % mod;
                }
            }
        }
        cout << res << ' ';
    }
    cout << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Task;
    A.init();
    while (Task--) {
        solve();
    }

    return 0;
}
