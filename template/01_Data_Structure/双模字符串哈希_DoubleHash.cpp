/*
 * 算法：双模字符串哈希 (Double String Hash)
 * 特点：O(1) 查询任意子串的哈希值，防止 Hash 冲突
 */
#include <bits/stdc++.h>
using namespace std;

struct DoubleHash {
    const long long M1 = 1e9 + 7, M2 = 1e9 + 9;
    const long long B1 = 131, B2 = 13331;
    vector<long long> h1, h2, p1, p2;

    DoubleHash(const string &s) {
        int n = s.length();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            p1[i + 1] = p1[i] * B1 % M1;
            p2[i + 1] = p2[i] * B2 % M2;
            h1[i + 1] = (h1[i] * B1 + s[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + s[i]) % M2;
        }
    }

    // 传入 1-based 的左闭右闭区间 [L, R]
    pair<long long, long long> get(int L, int R) {
        long long res1 = (h1[R] - h1[L - 1] * p1[R - L + 1] % M1 + M1) % M1;
        long long res2 = (h2[R] - h2[L - 1] * p2[R - L + 1] % M2 + M2) % M2;
        return {res1, res2};
    }
};