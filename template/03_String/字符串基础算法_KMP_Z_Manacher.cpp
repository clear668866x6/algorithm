/*
 * 算法：字符串三大基础神器 (KMP / Z函数(exKMP) / Manacher)
 * 复杂度：均为 O(N)
 */
#include <bits/stdc++.h>
using namespace std;

namespace StringAlgo {
    // 1. KMP (求 next 数组，即最长公共前后缀)
    // 返回的 pi[i] 表示 s[0...i] 的最长公共前后缀长度
    vector<int> get_pi(const string &s) {
        int n = s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    // 2. Z函数 / exKMP (求所有后缀与原串的最长公共前缀)
    // 返回的 z[i] 表示 s[i...n-1] 与 s[0...n-1] 的最长公共前缀长度
    vector<int> get_z(const string &s) {
        int n = s.length();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r && z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            }
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        return z;
    }

    // 3. Manacher 马拉车 (求最长回文子串)
    // 自动插入 '#'，返回的 p[i] 表示以 i 为中心的回文半径
    // 实际最长回文串长度就是 max(p) - 1
    vector<int> manacher(const string &s) {
        string t = "$#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        t += '^';
        int n = t.length(), r = 0, c = 0;
        vector<int> p(n);
        for (int i = 1; i < n - 1; i++) {
            p[i] = (r > i) ? min(p[2 * c - i], r - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) p[i]++;
            if (i + p[i] > r) {
                r = i + p[i];
                c = i;
            }
        }
        return p;
    }
} // namespace StringAlgo