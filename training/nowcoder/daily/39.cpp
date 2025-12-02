#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    string s;
    int b;
    cin >> s >> b;
    int a = 0;
    for (auto x : s) {
        a = a * 10 + x - '0';
        a %= b;
    }
    cout << gcd(a, b);
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Task--) {
        solve();
    }

    return 0;
}