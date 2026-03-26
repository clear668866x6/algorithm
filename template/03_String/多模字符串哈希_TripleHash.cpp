/*
 * 算法：多模字符串哈希 (Triple Hash)
 * 特点：利用运算符重载，计算极其优雅，绝不冲突
 */
#include <bits/stdc++.h>
using namespace std;

namespace MultiHash {
    constexpr long long MOD0 = 998244353;
    constexpr long long MOD1 = 1000000007;
    constexpr long long MOD2 = 1000000009;
    constexpr long long BASE = 13331; // 基数

    struct MOD {
        long long x0, x1, x2; // 改用 long long，彻底杜绝乘法溢出
        MOD() : x0(0), x1(0), x2(0) {}
        MOD(long long x0, long long x1, long long x2) : x0(x0), x1(x1), x2(x2) {}
    };

    MOD operator+(const MOD &a, const MOD &b) {
        return {(a.x0 + b.x0) % MOD0, (a.x1 + b.x1) % MOD1, (a.x2 + b.x2) % MOD2};
    }

    MOD operator-(const MOD &a, const MOD &b) {
        return {(a.x0 - b.x0 + MOD0) % MOD0, (a.x1 - b.x1 + MOD1) % MOD1, (a.x2 - b.x2 + MOD2) % MOD2};
    }

    MOD operator*(const MOD &a, const MOD &b) {
        return {(a.x0 * b.x0) % MOD0, (a.x1 * b.x1) % MOD1, (a.x2 * b.x2) % MOD2};
    }

    bool operator==(const MOD &a, const MOD &b) {
        return a.x0 == b.x0 && a.x1 == b.x1 && a.x2 == b.x2;
    }

    // 哈希预处理与查询类
    struct StringHash {
        vector<MOD> h, p;

        // 传入字符串进行预处理 (下标从 0 开始的 string)
        StringHash(const string &s) {
            int n = s.length();
            h.assign(n + 1, MOD());
            p.assign(n + 1, MOD());
            p[0] = MOD(1, 1, 1);
            MOD base(BASE, BASE, BASE);

            for (int i = 0; i < n; i++) {
                p[i + 1] = p[i] * base;
                MOD c(s[i], s[i], s[i]);
                h[i + 1] = h[i] * base + c;
            }
        }

        // 查询 1-based 下标区间[l, r] 的哈希值
        MOD get(int l, int r) {
            // 优雅得就像普通数字的十进制提取一样： h[r] - h[l-1] * 10^(r - l + 1)
            return h[r] - h[l - 1] * p[r - l + 1];
        }
    };
} // namespace MultiHash