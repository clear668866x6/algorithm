/*
 * 算法：笛卡尔树 (Cartesian Tree)
 * 复杂度：建树 O(N)
 * 功能：将序列问题转化为树上问题 (如 RMQ 转化为 LCA)
 * 构造原理：本板子以建立【小根笛卡尔树】为例（父节点值 < 子节点值）
 */
#include <bits/stdc++.h>
using namespace std;

struct CartesianTree {
    int n;
    int root; // 树根的下标
    vector<int> ls, rs; // 左右儿子数组

    CartesianTree(const vector<int> &a) {
        n = a.size() - 1;
        ls.assign(n + 1, 0);
        rs.assign(n + 1, 0);
        vector<int> stk; // 单调栈，存下标

        for (int i = 1; i <= n; i++) {
            int last_pop = 0;
            // 维护一个值递增的单调栈 (如果是大根树，这里改成 a[stk.back()] < a[i])
            while (!stk.empty() && a[stk.back()] > a[i]) {
                last_pop = stk.back();
                stk.pop_back();
            }
            if (!stk.empty()) {
                rs[stk.back()] = i; // 栈顶的右儿子是当前节点
            }
            ls[i] = last_pop; // 当前节点的左儿子是最后弹出的节点
            stk.push_back(i);
        }
        // 栈底元素即为全局最小值，也就是树根
        root = stk.front();
    }
};