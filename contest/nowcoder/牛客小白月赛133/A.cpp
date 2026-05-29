#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    string s;
    cin >> s;

    if (s == "awdec") {
        cout << "Fantasy_Blue";
    } else if (s == "Fantasy_Blue") {
        cout << "awdec";
    } else {
        cout << "other";
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