#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;

    int cur = 1000;

    vector<int> w(8, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cur += x;
        if (cur < 700) {
            w[0]++;
        } else if (cur < 1100) {
            w[1]++;
        } else if (cur < 1500) {
            w[2]++;
        } else if (cur < 2000) {
            w[3]++;
        } else if (cur < 2400) {
            w[4]++;
        } else if (cur < 2800) {
            w[5]++;
        } else {
            w[6]++;
        }
    }

    for (int i = 0; i <= 6; i++) cout << w[i] << ' ';
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