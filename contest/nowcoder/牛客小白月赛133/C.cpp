#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;

    if (n < 17) {
        cout << "No\n";
    } else {

        string s1 = "awdec", s2 = "Fantasy_Blue";

        int ans1 = 12, ans2 = 5;

        vector<int> pre(n + 1, 1e9), suf(n + 2, 1e9);

        for (int i = 1; i <= n; i++) {
            if (i + 4 <= n) {
                int cnt = 0;
                for (int j = i; j <= i + 4; j++) {
                    if (s[j] != s1[j - i]) {
                        cnt++;
                    }
                }
                pre[i + 4] = min(pre[i + 3], cnt);
            }
        }

        for (int i = n; i >= 1; i--) {
            if (i - 4 >= 1) {
                int cnt = 0;
                for (int j = i - 4; j <= i; j++) {
                    if (s[j] != s1[j - i + 4]) {
                        cnt++;
                    }
                }
                suf[i - 4] = min(suf[i - 3], cnt);
            }
        }

        int ans = 17;

        for (int i = 1; i <= n; i++) {
            if (i + 11 <= n) {
                int cnt = 0;

                for (int j = i; j <= i + 11; j++) {
                    if (s[j] != s2[j - i]) {
                        cnt++;
                    }
                }
                ans = min(ans, min(pre[i - 1], suf[i + 12]) + cnt);
            }
        }

        if (ans <= k) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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