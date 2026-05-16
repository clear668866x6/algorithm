#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    int n;
    cin >> s >> n;
    reverse(s.begin(), s.end());
    int t = n;
    reverse(s.begin(), s.end());
    while (t--) s.pop_back();
    for (int i = n; i < s.size(); i++) {
        cout << s[i];
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