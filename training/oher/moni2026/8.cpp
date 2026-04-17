#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        string s1, s2, s3;
        if (op == 1) {
            cin >> s1;
            if (s.find(s1) == -1) {
                cout << "-1\n";
            } else {
                cout << s.find(s1) << '\n';
            }
        } else if (op == 2) {
            cin >> s1 >> s2;
            if (s.find(s1) != -1) {
                int len = s1.size();
                s.replace(s.find(s1), len, s2);
            }
            cout << s << '\n';
        } else {
            char c1, c2;
            cin >> c1 >> c2 >> s3;
            string p;
            vector<int> d;
            for (int i = 1; i < s.size(); i++) {
                if (s[i - 1] == c1 && s[i] == c2) {
                    d.push_back(i);
                }
            }

            while (!d.empty()) {
                s.insert(d.back(), s3);
                d.pop_back();
            }
            cout << s << '\n';
        }
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