#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    if (w[1] == -1 and w[n] == -1) {
        cout << 0 << endl;
        cout << 0 << ' ';
        for (int i = 2; i < n; i++) cout << (w[i] == -1 ? 0 : w[i]) << ' ';
        cout << 0 << endl;
    } else if (w[1] == -1) {
        cout << 0 << endl;
        cout << w[n] << ' ';
        for (int i = 2; i <= n; i++) cout << (w[i] == -1 ? 0 : w[i]) << ' ';
        cout << endl;
    } else if (w[n] == -1) {
        cout << 0 << endl;
        for (int i = 1; i < n; i++) cout << (w[i] == -1 ? 0 : w[i]) << ' ';
        cout << w[1] << endl;
    } else {
        cout << abs(w[1] - w[n]) << endl;
        for (int i = 1; i <= n; i++) cout << (w[i] == -1 ? 0 : w[i]) << ' ';
        cout << endl;
    }
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