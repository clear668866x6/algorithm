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
    int n;
    cin >> n;
    V<int> w(n + 1, 0);
    FOR(i, 1, n) cin >> w[i];

    int mod = 1e9 + 7;

    function<int(int, int)> qmi = [&](int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    int ans = 0, lst = 1;

    FOR(l, 1, n) {
        bool f = false;
        FOR(r, l + 2, n) {
            if (w[l] > w[r]) {
                int cnt = 0;
                FOR(i, l + 1, r - 1) {
                    if (w[l] > w[i] && w[i] > w[r]) {
                        cnt++;
                    }
                }
                if (cnt) {
                    f = 1;
                    int del = r - l - 1 - cnt;
                    cout << l << ' ' << r << ' ' << lst << endl;
                    ans = (ans + qmi(2, l - lst) * (qmi(2, r - l - 1) - qmi(2, del) + mod) % mod) % mod;
                }
            }
        }
        if (f) lst = l;
    }

    cout << ((qmi(2, n) - ans) % mod + mod) % mod << endl;
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
