#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int x;
    cin >> x;

    int t = 90;

    for (int i = 0; i <= 10; i++) {
        string s = to_string(x - (t + i));
        for (auto y : s) {
            if (y == '9') {
                cout << t + i << ' ' << x - t - i << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
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