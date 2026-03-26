/*
 * 算法：对顶堆 (动态中位数 / 前k小之和)
 * 复杂度：插入/删除 O(log N)，查询 O(1)
 * 功能：动态维护数据流的中位数，支持随意删除元素，支持维护左右两半的区间和
 */
#include <bits/stdc++.h>
using namespace std;

struct MedianHeap {
    multiset<int> L, R; // L存较小的一半(大根堆性质)，R存较大的一半(小根堆性质)
    long long sumL = 0, sumR = 0;

    // 核心逻辑：保持 L 的大小始终等于 R 的大小，或者比 R 多 1
    void balance() {
        while (L.size() > R.size() + 1) {
            int val = *L.rbegin();
            R.insert(val);
            sumR += val;
            L.erase(prev(L.end()));
            sumL -= val;
        }
        while (L.size() < R.size()) {
            int val = *R.begin();
            L.insert(val);
            sumL += val;
            R.erase(R.begin());
            sumR -= val;
        }
    }

    void insert(int x) {
        if (L.empty() || x <= *L.rbegin()) {
            L.insert(x);
            sumL += x;
        } else {
            R.insert(x);
            sumR += x;
        }
        balance();
    }

    void erase(int x) {
        auto itL = L.find(x);
        if (itL != L.end()) {
            L.erase(itL);
            sumL -= x;
        } else {
            auto itR = R.find(x);
            if (itR != R.end()) {
                R.erase(itR);
                sumR -= x;
            }
        }
        balance();
    }

    int get_median() {
        if (L.empty()) return 0; // 视情况返回
        return *L.rbegin();
    }

    // 例如：求把所有数字变成中位数的最小代价 (常用于绝对值之和最小化)
    long long get_cost() {
        if (L.empty()) return 0;
        long long mid = get_median();
        // 右半边之和 - mid * 右半边个数 + mid * 左半边个数 - 左半边之和
        return (sumR - mid * R.size()) + (mid * L.size() - sumL);
    }
};