/*
 * 算法：折半搜索 (Meet in the Middle)
 * 作用：将 2^40 的复杂度降为 2^20 * log(2^20)
 */
#include <bits/stdc++.h>
using namespace std;

struct MeetInTheMiddle {
    long long target;

    vector<long long> get_subsets(const vector<long long> &a) {
        int n = a.size();
        vector<long long> res;
        for (int i = 0; i < (1 << n); i++) {
            long long sum = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) sum += a[j];
            }
            res.push_back(sum);
        }
        return res;
    }

    long long solve(vector<long long> &w, long long x) {
        target = x;
        int n = w.size();
        int mid = n / 2;

        vector<long long> A(w.begin(), w.begin() + mid);
        vector<long long> B(w.begin() + mid, w.end());

        vector<long long> subA = get_subsets(A);
        vector<long long> subB = get_subsets(B);

        sort(subA.begin(), subA.end());
        sort(subB.begin(), subB.end());

        long long ans = 0;
        // 遍历左半边，二分右半边
        for (long long val : subA) {
            auto l = lower_bound(subB.begin(), subB.end(), target - val);
            auto r = upper_bound(subB.begin(), subB.end(), target - val);
            ans += (r - l); // 统计和恰好为 target 的方案数
        }
        return ans;
    }
};