/*
 * 算法：ST表 (Sparse Table)
 * 复杂度：预处理 O(N log N)，单次查询 O(1)
 * 功能：解决静态区间的 RMQ (最值) 或 GCD 问题
 */
#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SparseTable {
    int n;
    vector<vector<T>> st;

    // 自定义合并函数，这里以 max 为例，也可换成 gcd, min 等
    T merge(const T &a, const T &b) {
        return max(a, b);
    }

    SparseTable(const vector<T> &a) {
        n = a.size() - 1;
        int max_log = 32 - __builtin_clz(n);
        st.assign(max_log, vector<T>(n + 1));

        for (int i = 1; i <= n; i++) {
            st[0][i] = a[i];
        }
        for (int j = 1; j < max_log; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) {
        if (l > r) swap(l, r);
        int k = __lg(r - l + 1);
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};