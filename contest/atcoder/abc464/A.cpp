#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;

    int a = 0, b = 0;

    for (auto x : s) {
        if (x == 'W') {
            a++;
        } else {
            b++;
        }
    }

    if (a > b) {
        cout << "West";
    } else {
        cout << "East";
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