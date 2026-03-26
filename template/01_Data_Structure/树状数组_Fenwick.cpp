/*
 * 算法：树状数组 (Fenwick Tree / BIT)
 * 复杂度：单次操作 O(log N)
 * 注意：下标必须从 1 开始！不要传入 0 否则死循环！
 */
#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Fenwick {
    int n;
    vector<T> tr;

    Fenwick(int n) : n(n), tr(n + 1, 0) {}

    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) {
            tr[i] += v;
        }
    }

    T query(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += tr[i];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};