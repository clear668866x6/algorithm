#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    map<char, int> s1, s2;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            s1[s[i]]++;
        } else {
            s2[s[i]]++;
        }
    }

    if (n & 1) {

        if (((n + 1) / 2) & 1) {
            int f1 = 0, f2 = 0;
            for (auto [x, y] : s1) {
                if (y & 1) {
                    f1++;
                    if (f1 >= 2) {
                        cout << "NO\n";
                        return;
                    }
                }
            }

            for (auto [x, y] : s2) {
                if (y & 1) {
                    cout << "NO\n";
                    return;
                }
            }

            cout << "YES\n";

        } else {
            int f1 = 0, f2 = 0;
            for (auto [x, y] : s2) {
                if (y & 1) {
                    f1++;
                    if (f1 >= 2) {
                        cout << "NO\n";
                        return;
                    }
                }
            }

            for (auto [x, y] : s1) {
                if (y & 1) {
                    cout << "NO\n";
                    return;
                }
            }

            cout << "YES\n";
        }

    } else {
        if (s1 != s2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}