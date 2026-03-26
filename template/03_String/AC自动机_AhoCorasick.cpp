/*
 * 算法：AC自动机 (Aho-Corasick Automaton)
 * 复杂度：O(模式串总长 + 文本串长度)
 */
#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    vector<vector<int>> tr;
    vector<int> fail, cnt;
    int idx;

    AhoCorasick(int max_nodes) {
        tr.assign(max_nodes + 10, vector<int>(26, 0));
        fail.assign(max_nodes + 10, 0);
        cnt.assign(max_nodes + 10, 0);
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

    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (tr[0][i]) q.push(tr[0][i]);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[u][i]) {
                    fail[tr[u][i]] = tr[fail[u]][i];
                    q.push(tr[u][i]);
                } else {
                    tr[u][i] = tr[fail[u]][i]; // 路径压缩 (Trie图)
                }
            }
        }
    }

    // 匹配文本串，返回匹配到的模式串总数
    int query(const string &t) {
        int p = 0, ans = 0;
        for (char c : t) {
            p = tr[p][c - 'a'];
            for (int j = p; j && cnt[j] != -1; j = fail[j]) {
                ans += cnt[j];
                cnt[j] = -1; // 打上标记，防止重复计算
            }
        }
        return ans;
    }
};