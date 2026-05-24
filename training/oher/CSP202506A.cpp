#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int t1 = (c - a) * 10 / b;
    int t2 = (c - a) * 100 / b % 10;

    cout << t1 + 1 << ' ' << t2 + 1 << '\n';
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