/*
 * 算法：欧拉线性筛 (同时筛素数、莫比乌斯函数、欧拉函数、约数个数)
 * 复杂度：O(N) 严格线性
 */
#include <bits/stdc++.h>
using namespace std;

struct Sieve {
    int n;
    vector<int> primes, min_prime;
    vector<int> mu; // 莫比乌斯函数
    vector<int> phi; // 欧拉函数
    vector<int> d; // 约数个数
    vector<int> num; // 最小质因子的幂次 (辅助求 d)

    Sieve(int n) : n(n) {
        min_prime.assign(n + 1, 0);
        mu.assign(n + 1, 0);
        phi.assign(n + 1, 0);
        d.assign(n + 1, 0);
        num.assign(n + 1, 0);

        mu[1] = phi[1] = d[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!min_prime[i]) { // 是素数
                min_prime[i] = i;
                primes.push_back(i);
                mu[i] = -1;
                phi[i] = i - 1;
                d[i] = 2;
                num[i] = 1;
            }
            for (int p : primes) {
                if (i * p > n) break;
                min_prime[i * p] = p;
                if (i % p == 0) {
                    mu[i * p] = 0;
                    phi[i * p] = phi[i] * p;
                    num[i * p] = num[i] + 1;
                    d[i * p] = d[i] / (num[i] + 1) * (num[i * p] + 1);
                    break;
                }
                mu[i * p] = -mu[i];
                phi[i * p] = phi[i] * (p - 1);
                num[i * p] = 1;
                d[i * p] = d[i] * 2;
            }
        }
    }
};