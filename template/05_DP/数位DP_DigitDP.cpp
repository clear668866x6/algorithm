/*
 * =========================================================================================
 * 算法：数位 DP (通用单次 DFS 状态压缩模板)
 * =========================================================================================
 *
 * 【核心参数释义】
 * 1. pos (或 u) : 当前正在填第几位（通常从最高位 n-1 开始往下倒推，填到 -1 结束）。
 * 2. state      : 题目要求的各种状态（例如：各位数字之和 mod 3 的余数、mask 二进制记录出现过的数字等）。
 * 3. lim (limit): 【天花板限制】表示当前所填的数字前缀，是否正紧紧贴着上限 N 的前缀。
 *                 - 若 lim == true : 当前位受到上限压制，最多只能填到 num[pos]（例如 N=314，百位最多填3）。
 *                 - 若 lim == false: 之前某位已经填了更小的数，天花板被打破，当前位彻底自由，可以填 0~9。
 * 4. lead       : 【前导零标记】表示当前是否还处于“全0占位”的虚无阶段。
 *                 - 若 lead == true : 前面填的全是 0。此时如果当前位继续填 0，这个 0 是“空气”，
 *                                     不能算作数字 0 出现，不应该更新 state！
 *                 - 若 lead == false: 已经填过有效数字，后面的 0 都是真实的数字 0。
 *
 * 【初始传参法则】 -> dfs(n - 1, 0..., true, true)
 * - 必须传 lim = true : 一开始在最高位，必须受到 N 的限制，否则最高位填 9 就直接越界了。
 * - 必须传 lead = true: 一开始什么有效数字都没填，必须开启前导零屏蔽，防止把占位 0 算进去。
 *
 * 【记忆化黄金法则】 -> if (!lim && !lead) memo[...] = ans;
 * - 只记忆化 lim=false 且 lead=false 的【完全自由状态】！
 * - 为什么？
 *   1. 受限状态 (lim=true) 算出的答案是残缺的（顺着 N 的边缘走，分支少），不能套用到普通状态。
 *   2. 前导零状态 (lead=true) 带有无意义的 0，不能作为普适答案复用。
 *   只有当彻底自由时，搜出来的才是完整子树（例如完整的 00~99 的方案数），才能存入备忘录供后续秒查！
 *
 * 【易错点特判】
 * - 当 pos == -1（搜到终点）时，如果此时 lead == true，说明从头到尾全填了 0，代表数字 0。
 * - 绝大多数题目要求 1 <= x <= N，因此数字 0 是不合法的，记得加一句：if (lead) return 0;
 * =========================================================================================
 */
#include <bits/stdc++.h>
using namespace std;

struct DigitDP {
    vector<int> num;
    long long memo[20][10]; // 第一维是数位，第二维是自定义状态(比如前一个数字)

    long long dfs(int pos, int state, bool limit, bool lead) {
        if (pos == -1) {
            return 1; // 边界：成功搜到底，返回一种合法方案
            // return !lead &&条件    说明无前导零满足的条件
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