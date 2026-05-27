#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int mod = 998244353;

struct RMQ {
    static constexpr int N = 1e6 + 1;
    int f[20][N];

    void init(const vector<int> &w, int n) {
        for (int i = 1; i <= n; i++) f[0][i] = w[i];
        for (int j = 1; j <= 19; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[j][i] = gcd(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    i64 query(int l, int r) {
        int len = __lg(r - l + 1);
        return std::gcd(f[len][l], f[len][r - (1 << len) + 1]);
    }

} A;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    i64 ans = 0;

    A.init(a, n);

    for (int L = 1; L <= n; L++) {
        i64 t = L, t2 = 0;
        int R = L, val = a[L], lstR = -1;
        while (R <= n) {

            if (val == 1) {
                lstR = R;
                R = n;
                i64 len = R - lstR + 1;
                i64 sum = (lstR + R) * len / 2 % mod;
                t2 = (t2 + sum) % mod;
                break;
            }
            int l = R;

            for (int j = __lg(n - l + 1); j >= 0; j--) {
                if (l + (1 << j) - 1 <= n) {
                    if (A.f[j][l] % val == 0) {
                        l += (1 << j);
                    }
                }
            }

            lstR = R;
            R = l - 1;
            i64 len = R - lstR + 1;
            i64 sum = (lstR + R) * len / 2 % mod;
            t2 = (t2 + 1LL * val * sum) % mod;
            R++;
            if (R <= n) {
                val = std::gcd(val, a[R]);
            }
        }
        ans = (ans + t * t2 % mod) % mod;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}