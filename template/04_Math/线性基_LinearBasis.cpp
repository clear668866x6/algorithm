/*
 * 算法：线性基 (普通版 + 贪心带时间戳版)
 * 作用：求序列的异或最大值、判断异或能否得到某个数
 */
#include <bits/stdc++.h>
using namespace std;

// 【进阶：带时间戳的贪心线性基】 - 支持查询 [L, R] 区间的线性基
// 用法：从左到右 insert(val, i)，然后查 query_max(L)
struct TimeLinearBasis {
    static const int MAXL = 60; // 60 对于 1e18，30 对于 1e9
    long long d[MAXL + 1];
    int t[MAXL + 1]; // 记录每一位是由原数组的哪个下标贡献的

    TimeLinearBasis() {
        memset(d, 0, sizeof(d));
        memset(t, 0, sizeof(t));
    }

    void insert(long long x, int time_tag) {
        for (int i = MAXL; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!d[i]) {
                    d[i] = x;
                    t[i] = time_tag;
                    return;
                }
                // 贪心：如果要插入的数比当前位的时间戳晚，就强行替换，把老的踢下去
                if (t[i] < time_tag) {
                    swap(t[i], time_tag);
                    swap(d[i], x);
                }
                x ^= d[i];
            }
        }
    }

    // 查询下标大于等于 L 的元素组成的异或最大值
    long long query_max(int L) {
        long long res = 0;
        for (int i = MAXL; i >= 0; i--) {
            if (t[i] >= L) { // 只有时间戳合法才能用
                res = max(res, res ^ d[i]);
            }
        }
        return res;
    }
};