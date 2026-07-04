#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    int l = 1, r = n, idx = n;
    int p = 0;

    vector<int> ans(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        if (s[i] == 'o') {
            if (p == 0) {
                ans[l++] = idx--;
                p ^= 1;
            } else {
                ans[r--] = idx--;
                p ^= 1;
            }
        } else {
            if (p == 1) {
                ans[l++] = idx--;
            } else {
                ans[r--] = idx--;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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