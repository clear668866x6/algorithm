#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) cout << s[i];
    cout << "-";
    for (int i = 3; i < 7; i++) cout << s[i];
    cout << "-";
    for (int i = 7; i < s.size(); i++) cout << s[i];
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