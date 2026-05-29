#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    string s;
    getline(cin, s);
    cin >> n;
    cin.ignore();

    vector<vector<char>> g(256);
    vector<int> p(256, 0), siz(256, 1);
    iota(p.begin(), p.end(), 0ll);

    function<int(int)> find = [&](int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    };

    for (int i = 1; i <= n; i++) {
        string s2;
        getline(cin, s2);
        char c1 = s2[1], c2 = s2[2];
        g[c1].push_back(c2);
        c1 = find(c1), c2 = find(c2);
        if (c1 != c2) {
            p[c1] = c2;
            siz[c2] += siz[c1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        for (auto y : s) {
            if (y == '#') {
                cout << y;
            } else {
                int t = siz[find(y)], p = x % t;
                while (p--) {
                    y = g[y][0];
                }
                cout << char(y);
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}