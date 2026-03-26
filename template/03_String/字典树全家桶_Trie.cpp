/*
 * 算法：字典树全家桶 (普通 Trie + 01-Trie)
 * 复杂度：O(字符集大小 / 异或位数)
 */
#include <bits/stdc++.h>
using namespace std;

// 【普通字典树】 - 字符串查前缀
struct Trie {
    vector<vector<int>> tr;
    vector<int> cnt;
    int idx;

    Trie(int max_len = 100000) {
        tr.assign(max_len + 10, vector<int>(26, 0));
        cnt.assign(max_len + 10, 0);
        idx = 0;
    }

    void insert(const string &s) {
        int p = 0;
        for (char c : s) {
            int u = c - 'a';
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
        }
        cnt[p]++;
    }
};

// 【01 字典树】 - 处理极其强大的异或极值问题
struct Trie01 {
    vector<array<int, 2>> tr;
    vector<int> cnt;
    int idx;
    int max_bit; // 通常是 29 (对于 1e9)，或者 60 (对于 1e18)

    Trie01(int max_nodes = 3000000, int max_bit = 29) : max_bit(max_bit) {
        tr.assign(max_nodes + 10, {0, 0});
        cnt.assign(max_nodes + 10, 0);
        idx = 0;
    }

    void insert(int x, int val = 1) { // val=1为插入，val=-1为删除
        int p = 0;
        for (int i = max_bit; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
            cnt[p] += val;
        }
    }

    // 寻找与 x 异或结果最大的数
    int query_max(int x) {
        int p = 0, ans = 0;
        for (int i = max_bit; i >= 0; i--) {
            int u = (x >> i) & 1;
            // 贪心：优先走相反的位
            if (tr[p][u ^ 1] && cnt[tr[p][u ^ 1]] > 0) {
                p = tr[p][u ^ 1];
                ans |= (1 << i);
            } else {
                p = tr[p][u];
            }
        }
        return ans; // 返回的是异或后的最大值
    }
};