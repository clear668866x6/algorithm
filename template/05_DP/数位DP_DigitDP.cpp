/*
 * 算法：数位 DP (通用记忆化搜索模板)
 * 核心法则：只记忆化 limit=false 且 lead=false 的完全自由状态！
 */
#include <bits/stdc++.h>
using namespace std;

struct DigitDP {
    vector<int> num;
    long long memo[20][10]; // 第一维是数位，第二维是自定义状态(比如前一个数字)

    long long dfs(int pos, int state, bool limit, bool lead) {
        if (pos == -1) {
            return 1; // 边界：成功搜到底，返回一种合法方案
        }
        // 记忆化：只有不在边界限制且没有前导零时，才能复用状态
        if (!limit && !lead && memo[pos][state] != -1) {
            return memo[pos][state];
        }

        long long res = 0;
        int up = limit ? num[pos] : 9; // 当前位的最大上限

        for (int i = 0; i <= up; i++) {
            if (lead && i == 0) {
                // 如果全是前导零，传递下去 (状态根据题目可能传 0 或者特殊值)
                res += dfs(pos - 1, 0, limit && i == up, true);
            } else {
                // 具体的题目约束写在这里 (例如不允许出现连续相同的数)
                // if (i == state) continue;

                res += dfs(pos - 1, i, limit && i == up, false);
            }
        }

        // 只记录自由状态
        if (!limit && !lead) {
            memo[pos][state] = res;
        }
        return res;
    }

    long long solve(long long x) {
        if (x < 0) return 0; // 防止负数
        num.clear();
        memset(memo, -1, sizeof(memo));
        if (x == 0) num.push_back(0);
        while (x) {
            num.push_back(x % 10);
            x /= 10;
        }
        // 从最高位向下搜
        return dfs(num.size() - 1, 0, true, true);
    }
};