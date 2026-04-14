#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct Comb {
    static constexpr int N = 2e5 + 10;

    i64 fac[N], infac[N];

    i64 qmi(i64 a, i64 b) {
        i64 ans = 1;
        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return ans;
    }

    void init() {
        int n = N - 10;
        fac[0] = infac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
        infac[n] = qmi(fac[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) infac[i] = infac[i + 1] * (i + 1) % mod;
    }

    i64 C(i64 x, i64 y) {
        if (x < 0 || y < 0 || x - y < 0) return 0;
        return fac[x] * infac[y] % mod * infac[x - y] % mod;
    }

} A;

void solve() {
    int n;
    cin >> n;

    vector<i64> l(n + 1, 0), r(n + 1, 0);
    vector<i64> da(n + 2, 0), db(n + 2, 0), dc(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        da[l[i]]++, da[r[i] + 1]--;
        db[n - r[i]]++, db[n - l[i] + 1]--;
        int L = max(l[i], n - r[i]);
        int R = min(r[i], n - l[i]);
        if (L <= R) {
            dc[max(l[i], n - r[i])]++, dc[min(r[i], n - l[i]) + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        da[i] += da[i - 1];
        db[i] += db[i - 1];
        dc[i] += dc[i - 1];
    }

    i64 ans = 0;

    for (int x = 1; x <= n - 1; x++) {
        i64 ta = da[x] - dc[x];
        i64 tb = db[x] - dc[x];
        i64 tc = dc[x];
        i64 non = n - (ta + tb + tc);
        if (non > 0 || ta > x || tb > n - x) continue;
        i64 re = x - ta;
        ans = (ans + A.C(tc, re)) % mod;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    A.init();
    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}