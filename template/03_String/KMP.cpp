#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

struct KMP {
    string p;
    vector<int> nxt;

    KMP(const string &_p) : p(_p) {
        int m = p.size();
        nxt.assign(m + 1, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && p[i] != p[j]) j = nxt[j];
            if (p[i] == p[j]) j++;
            nxt[i + 1] = j;
        }
    }

    vector<int> match(const string &s) {
        vector<int> res;
        int n = s.size(), m = p.size();
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && s[i] != p[j]) j = nxt[j];
            if (s[i] == p[j]) j++;
            if (j == m) {
                res.push_back(i - m + 1);
                j = nxt[j];
            }
        }
        return res;
    }

    void print_nxt() {
        for (int i = 1; i <= p.size(); i++) {
            cout << nxt[i] << (i == p.size() ? "" : " ");
        }
        cout << "\n";
    }
};

void solve() {
    string s, t;
    if (!(cin >> s >> t)) return;

    KMP kmp(t);

    vector<int> pos = kmp.match(s);

    for (int x : pos) {
        cout << x + 1 << "\n";
    }

    kmp.print_nxt();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}