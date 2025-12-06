#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            if (x * 2 + y * 4 == n) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    int Task = 1;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Task;

    while (Task--) {
        solve();
    }

    return 0;
}