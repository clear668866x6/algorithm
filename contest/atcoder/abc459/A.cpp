#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s = "HelloWorld";
    int x;
    cin >> x;

    for (int i = 0; i < s.size(); i++) {
        if (i == x - 1) continue;
        cout << char(s[i]);
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