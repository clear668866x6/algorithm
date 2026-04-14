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

    reverse(s.begin(), s.end());

    while (s.back() == 'o') s.pop_back();

    reverse(s.begin(), s.end());

    cout << s;
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