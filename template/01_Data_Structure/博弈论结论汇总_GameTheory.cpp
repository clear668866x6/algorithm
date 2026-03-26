#include <bits/stdc++.h>
using namespace std;

namespace GameTheory {
    // 1. 巴什博弈 (Bash)
    // n个石子，每次最多取 m 个。先手必胜返回 true。
    bool Bash(long long n, long long m) {
        return n % (m + 1) != 0;
    }

    // 2. 威佐夫博弈 (Wythoff)
    // 两堆石子 a 和 b，每次可以取一堆的任意个，或两堆取相同个。
    bool Wythoff(long long a, long long b) {
        if (a > b) swap(a, b);
        long double gold = (1.0 + sqrt(5.0)) / 2.0;
        long long k = b - a;
        return a != (long long)(gold * k);
    }

    // 3. 尼姆博弈 (Nim)
    // 多堆石子，每次在一堆中取任意个。所有石子异或和不为0则先手必胜。
    bool Nim(const vector<int> &piles) {
        int xor_sum = 0;
        for (int x : piles) xor_sum ^= x;
        return xor_sum != 0;
    }
} // namespace GameTheory