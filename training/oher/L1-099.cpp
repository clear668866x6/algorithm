#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
        if (b == 0) {
            cout << "biii\nstop";
        } else {
            cout << "-\nstop";
        }
    } else if (a == 1) {
        if (b == 0) {
            cout << "dudu\nmove";
        } else {
            cout << "-\nmove";
        }
    } else {
        cout << "-\nstop";
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