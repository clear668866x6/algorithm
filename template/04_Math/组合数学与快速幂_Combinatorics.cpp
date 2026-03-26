/*
 * 算法：组合数学全家桶 (逆元、阶乘、C(n, m))
 * 复杂度：预处理 O(N)，查询 O(1)
 */
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Comb {
    int n, MOD;
    vector<i64> fac, invfac;

    i64 qpow(i64 a, i64 b) {
        i64 res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    i64 inv(i64 a) {
        return qpow(a, MOD - 2);
    }

    Comb(int n, int MOD = 998244353) : n(n), MOD(MOD) {
        fac.assign(n + 1, 1);
        invfac.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
        invfac[n] = inv(fac[n]);
        for (int i = n - 1; i >= 0; i--) {
            invfac[i] = invfac[i + 1] * (i + 1) % MOD;
        }
    }

    i64 C(int n, int m) {
        if (m < 0 || m > n || n < 0) return 0;
        return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
    }

    i64 A(int n, int m) {
        if (m < 0 || m > n || n < 0) return 0;
        return fac[n] * invfac[n - m] % MOD;
    }
};